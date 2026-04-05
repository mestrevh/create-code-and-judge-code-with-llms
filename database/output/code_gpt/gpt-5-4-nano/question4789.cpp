/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Game {
    vector<vector<int>> cols;

    void removeEmpty() {
        vector<vector<int>> ncols;
        ncols.reserve(cols.size());
        for (auto &c : cols) if (!c.empty()) ncols.push_back(std::move(c));
        cols.swap(ncols);
    }

    void addColLeft(int color) {
        vector<int> c;
        c.push_back(color);
        cols.insert(cols.begin(), std::move(c));
    }
    void addColRight(int color) {
        vector<int> c;
        c.push_back(color);
        cols.push_back(std::move(c));
    }

    void stabilizeFromTop(size_t idx) {
        while (true) {
            if (idx >= cols.size()) return;
            auto &col = cols[idx];
            if (col.empty()) return;
            int color = col.back();
            int cnt = 1;
            for (int i = (int)col.size() - 2; i >= 0; --i) {
                if (col[i] == color) cnt++;
                else break;
            }
            if (cnt < 2) return;
            col.resize(col.size() - cnt);
            if (col.empty()) {
                cols.erase(cols.begin() + (ptrdiff_t)idx);
                return;
            }
            if (idx >= cols.size()) return;
        }
    }

    void addOnColumn(int pos, int color) {
        if (pos == 0) {
            addColLeft(color);
            return;
        }
        if (pos == (int)cols.size() + 1) {
            addColRight(color);
            return;
        }
        int idx = pos - 1;
        if (idx < 0) idx = 0;
        if (idx >= (int)cols.size()) idx = (int)cols.size() - 1;
        cols[idx].push_back(color);
        stabilizeFromTop((size_t)idx);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P;
    if (!(cin >> P)) return 0;
    for (int tc = 0; tc < P; tc++) {
        Game g;
        int S, C;
        while (true) {
            string token;
            if (!(cin >> token)) break;
            if (token == "END") break;
            S = stoi(token);
            cin >> C;
            int N = (int)g.cols.size();
            int pos = S;
            if (pos == 0) {
                g.addColLeft(C);
            } else if (pos == N + 1) {
                g.addColRight(C);
            } else {
                int idx = pos - 1;
                g.cols[idx].push_back(C);
                g.stabilizeFromTop((size_t)idx);
            }
        }

        string dummy;
        getline(cin, dummy);
        while (true) {
            streampos before = cin.tellg();
            if (!getline(cin, dummy)) break;
            if (dummy.size() == 0) break;
        }

        cout << "caso " << tc << ":";
        if (!g.cols.empty()) {
            for (auto &col : g.cols) {
                int top = col.empty() ? -1 : col.back();
                cout << " " << top;
            }
        }
        cout << "\n";
    }
    return 0;
}