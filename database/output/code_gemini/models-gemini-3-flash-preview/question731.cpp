/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    for (int t = 1; t <= T; ++t) {
        int N;
        if (!(cin >> N)) break;

        vector<int> cite(N + 1);
        vector<int> in_deg_total(N + 1, 0);
        vector<int> in_deg_no_self(N + 1, 0);

        for (int i = 1; i <= N; ++i) {
            int x;
            cin >> x;
            cite[i] = x;
            if (x != 0) {
                in_deg_total[x]++;
                if (x != i) {
                    in_deg_no_self[x]++;
                }
            }
        }

        int X = 0;
        for (int i = 1; i <= N; ++i) {
            if (in_deg_total[i] == 0) {
                X++;
            }
        }

        vector<bool> is_suspicious(N + 1, false);
        queue<int> Q;
        for (int i = 1; i <= N; ++i) {
            if (in_deg_no_self[i] == 0) {
                is_suspicious[i] = true;
                Q.push(i);
            }
        }

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            int v = cite[u];
            if (v != 0 && v != u) {
                if (!is_suspicious[v]) {
                    in_deg_no_self[v]--;
                    if (in_deg_no_self[v] == 0) {
                        is_suspicious[v] = true;
                        Q.push(v);
                    }
                }
            }
        }

        int Y = 0;
        for (int i = 1; i <= N; ++i) {
            if (is_suspicious[i]) {
                Y++;
            }
        }

        cout << "Caso #" << t << ": " << X << " " << Y << "\n";
    }

    return 0;
}