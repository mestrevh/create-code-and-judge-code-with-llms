/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to;
    int type;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, E, S, M;
    if (!(cin >> N >> E >> S >> M)) return 0;

    vector<vector<Edge>> adj(N);
    for (int i = 0; i < M; ++i) {
        int u, v, t_type;
        cin >> u >> v >> t_type;
        if (u >= 0 && u < N) {
            adj[u].push_back({v, t_type});
        }
    }

    // dist[node][time % 3]
    vector<vector<int>> dist(N, vector<int>(3, -1));
    queue<pair<int, int>> q;

    if (E >= 0 && E < N) {
        dist[E][0] = 0;
        q.push(make_pair(E, 0));
    }

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int u = curr.first;
        int rem = curr.second;
        int d = dist[u][rem];

        if (u == S) {
            cout << d << "\n";
            return 0;
        }

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            const Edge& edge = adj[u][i];
            bool can_pass = false;
            
            // T=1 opens when t is a multiple of 3 (rem == 0)
            if (edge.type == 1) {
                if (rem == 0) can_pass = true;
            } 
            // T=0 closes when t is a multiple of 3 (rem != 0)
            else {
                if (rem != 0) can_pass = true;
            }

            if (can_pass) {
                int next_d = d + 1;
                int next_rem = next_d % 3;
                if (dist[edge.to][next_rem] == -1) {
                    dist[edge.to][next_rem] = next_d;
                    q.push(make_pair(edge.to, next_rem));
                }
            }
        }
    }

    cout << "*\n";
    return 0;
}