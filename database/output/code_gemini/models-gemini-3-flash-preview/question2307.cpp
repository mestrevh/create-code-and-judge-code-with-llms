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

    int X, Y, N;
    if (!(cin >> X >> Y >> N)) return 0;

    vector<vector<int>> adj(N + 1);
    for (int i = 1; i <= N; ++i) {
        int p;
        if (!(cin >> p)) break;
        if (p >= 0 && p <= N) {
            adj[p].push_back(i);
        }
    }

    vector<int> d(N + 1, -1);
    queue<int> q;
    d[0] = 0;
    q.push(0);

    int total_subs = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u != 0 && d[u] >= 1 && d[u] <= Y) {
            total_subs++;
        }

        if (d[u] < Y) {
            for (int v : adj[u]) {
                if (d[v] == -1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    if (total_subs >= X) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}