/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, A, T;
    if (!(cin >> V >> A >> T)) return 0;

    vector<vector<int>> adj(V);
    for (int i = 0; i < A; i++) {
        int O, D;
        cin >> O >> D;
        if (0 <= O && O < V && 0 <= D && D < V) adj[O].push_back(D);
    }
    for (int i = 0; i < V; i++) sort(adj[i].begin(), adj[i].end());

    for (int tc = 1; tc <= T; tc++) {
        int O, D;
        cin >> O >> D;

        cout << "Caso de Teste #" << tc << " - BFS(" << O << ")\n";

        vector<int> dist(V, -1), pred(V, -1);
        queue<int> q;
        dist[O] = 0;
        pred[O] = -1;
        q.push(O);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << "Iniciando busca em largura a partir de " << u << "\n";
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    pred[v] = u;
                    q.push(v);
                }
            }
        }

        for (int k = 0; k < V; k++) {
            cout << k << " | ";
            if (dist[k] == -1) cout << "-";
            else cout << dist[k];
            cout << " | ";
            if (pred[k] == -1) cout << "-";
            else cout << pred[k];
            cout << "\n";
        }

        if (dist[D] == -1) {
            cout << "Sem caminho entre " << O << " e " << D << "\n";
        } else {
            vector<int> path;
            for (int cur = D; cur != -1; cur = pred[cur]) path.push_back(cur);
            reverse(path.begin(), path.end());
            cout << "Caminho entre " << O << " e " << D << ": ";
            for (size_t i = 0; i < path.size(); i++) {
                if (i) cout << " => ";
                cout << path[i];
            }
            cout << "\n";
        }

        if (tc != T) cout << "\n";
    }

    return 0;
}