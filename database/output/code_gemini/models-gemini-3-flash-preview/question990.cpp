/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int P;
    if (!(cin >> P)) return 0;

    for (int k = 0; k < P; ++k) {
        vector<vector<int>> cols;
        string s;
        while (cin >> s && s != "END") {
            int S;
            try {
                S = stoi(s);
            } catch (...) {
                break;
            }
            int C;
            if (!(cin >> C)) break;

            int N = (int)cols.size();
            if (S == 0) {
                cols.insert(cols.begin(), vector<int>{C});
            } else if (S == N + 1) {
                cols.push_back(vector<int>{C});
            } else if (S >= 1 && S <= N) {
                int idx = S - 1;
                if (!cols[idx].empty() && cols[idx].back() == C) {
                    while (!cols[idx].empty() && cols[idx].back() == C) {
                        cols[idx].pop_back();
                    }
                    if (cols[idx].empty()) {
                        cols.erase(cols.begin() + idx);
                    }
                } else {
                    cols[idx].push_back(C);
                }
            }
        }

        cout << "caso " << k << ":";
        for (const auto& col : cols) {
            if (!col.empty()) {
                cout << " " << col.back();
            }
        }
        cout << "\n";
    }

    return 0;
}