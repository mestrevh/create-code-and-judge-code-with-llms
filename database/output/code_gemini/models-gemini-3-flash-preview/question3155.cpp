/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_LIMIT = 200007;
vector<int> adj[MAX_LIMIT];
vector<int> rev_adj[MAX_LIMIT];
bool reachable_from_S[MAX_LIMIT];
bool can_reach_T[MAX_LIMIT];

struct Edge {
    int u, v;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, E;
    if (!(cin >> N >> E)) return 0;

    vector<Edge> edges_input;
    int max_node_found = 0;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < MAX_LIMIT && v >= 0 && v < MAX_LIMIT) {
            adj[u].push_back(v);
            rev_adj[v].push_back(u);
            edges_input.push_back({u, v});
            if (u > max_node_found) max_node_found = u;
            if (v > max_node_found) max_node_found = v;
        }
    }

    int S, T;
    cin >> S >> T;
    if (S >= 0 && S < MAX_LIMIT && S > max_node_found) max_node_found = S;
    if (T >= 0 && T < MAX_LIMIT && T > max_node_found) max_node_found = T;

    if (S >= 0 && S < MAX_LIMIT) {
        queue<int> q;
        q.push(S);
        reachable_from_S[S] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (v >= 0 && v < MAX_LIMIT && !reachable_from_S[v]) {
                    reachable_from_S[v] = true;
                    q.push(v);
                }
            }
        }
    }

    if (T >= 0 && T < MAX_LIMIT) {
        queue<int> q;
        q.push(T);
        can_reach_T[T] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : rev_adj[u]) {
                if (v >= 0 && v < MAX_LIMIT && !can_reach_T[v]) {
                    can_reach_T[v] = true;
                    q.push(v);
                }
            }
        }
    }

    cout << "Nodes set:" << "\n";
    for (int i = 0; i <= max_node_found; ++i) {
        if (i < MAX_LIMIT && reachable_from_S[i] && can_reach_T[i]) {
            cout << i << "\n";
        }
    }

    vector<pair<int, int>> res_edges;
    for (const auto& e : edges_input) {
        if (e.u < MAX_LIMIT && e.v < MAX_LIMIT && reachable_from_S[e.u] && can_reach_T[e.v]) {
            res_edges.push_back({e.u, e.v});
        }
    }
    sort(res_edges.begin(), res_edges.end());
    res_edges.erase(unique(res_edges.begin(), res_edges.end()), res_edges.end());

    cout << "Edges set:" << "\n";
    for (const auto& edge : res_edges) {
        cout << "(" << edge.first << ", " << edge.second << ")" << "\n";
    }

    return 0;
}