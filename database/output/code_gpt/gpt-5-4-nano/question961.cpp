/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> st;
    SegTree() : n(0) {}
    SegTree(int n_) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n <<= 1;
        st.assign(2 * n, 0);
    }
    void pointUpdate(int idx, int val) {
        int p = idx + n;
        st[p] = val;
        for (p >>= 1; p >= 1; p >>= 1) st[p] = max(st[p << 1], st[p << 1 | 1]);
    }
    int rangeMax() const { return st[1]; }
    int get(int idx) const { return st[idx + n]; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXM = 1140;
    vector<multiset<int>> colSets(MAXM);
    SegTree colMax(MAXM);

    deque<vector<int>> days;
    vector<int> dayMax;

    auto ensureColMaxInit = [&]() {
        static bool inited = false;
        if (inited) return;
        inited = true;
        colMax.init(MAXM);
        for (int j = 0; j < MAXM; j++) colMax.pointUpdate(j, 0);
    };
    ensureColMaxInit();

    int t;
    while ( (cin >> t) ) {
        if (t == 0) break;

        if (t == 1) {
            int Q;
            cin >> Q;
            vector<int> vals(Q);
            int mx = 0;
            for (int i = 0; i < Q; i++) {
                cin >> vals[i];
                mx = max(mx, vals[i]);
            }
            days.push_back(std::move(vals));
            dayMax.push_back(mx);

            int idxDay = (int)days.size() - 1;
            (void)idxDay;

            for (int j = 0; j < Q; j++) {
                int v = days.back()[j];
                colSets[j].insert(v);
                int curMax = *colSets[j].rbegin();
                colMax.pointUpdate(j, curMax);
            }

            cout << days.size() << "\n";
        } else if (t == 2) {
            int d;
            cin >> d;
            auto &vec = days[d];
            for (int j = 0; j < (int)vec.size(); j++) {
                auto it = colSets[j].find(vec[j]);
                if (it != colSets[j].end()) colSets[j].erase(it);
                int curMax = colSets[j].empty() ? 0 : *colSets[j].rbegin();
                colMax.pointUpdate(j, curMax);
            }
            days.erase(days.begin() + d);
            dayMax.erase(dayMax.begin() + d);

            cout << days[d-0].size() << "\n"; 
        } else if (t == 3) {
            int i;
            cin >> i;
            cout << dayMax[i] << "\n";
        } else if (t == 4) {
            int j;
            cin >> j;
            cout << colMax.get(j) << "\n";
        }
    }

    return 0;
}