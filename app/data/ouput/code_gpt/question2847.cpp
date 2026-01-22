/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

bool bellman_ford(int n, vector<tuple<int, int, int>>& edges) {
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        for (auto& [u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    for (auto& [u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            return true; // ciclo negativo
        }
    }
    
    return false;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;
        vector<tuple<int, int, int>> edges(m);
        for (int i = 0; i < m; ++i) {
            int x, y, t;
            cin >> x >> y >> t;
            edges[i] = make_tuple(x, y, t);
        }
        if (bellman_ford(n, edges)) {
            cout << "possible" << endl;
        } else {
            cout << "not possible" << endl;
        }
    }
    return 0;
}
