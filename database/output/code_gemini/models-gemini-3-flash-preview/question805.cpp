/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * Problema: Busca em Largura (BFS) em um grafo direcionado.
 * O objetivo é realizar a BFS a partir de um vértice de origem, registrando distâncias,
 * predecessores e a ordem de visitação, respeitando a ordem crescente de vizinhos.
 */

int main() {
    // Otimização de I/O padrão em C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, A, T;
    if (!(cin >> V >> A >> T)) return 0;

    // Representação do grafo utilizando lista de adjacência
    vector<vector<int>> adj(V);
    for (int i = 0; i < A; ++i) {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj[u].push_back(v);
        }
    }

    // Ordenar vizinhos para garantir a visita em ordem crescente
    for (int i = 0; i < V; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    // Delimitador inicial
    cout << "--------" << endl;

    for (int t = 1; t <= T; ++t) {
        int start, target;
        cin >> start >> target;

        // Estruturas auxiliares da busca em largura
        vector<int> dist(V, -1);
        vector<int> pred(V, -1);
        vector<int> visit_order;
        queue<int> q;

        // Inicialização do vértice de origem
        if (start >= 0 && start < V) {
            dist[start] = 0;
            q.push(start);
        }

        // Execução do algoritmo BFS
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visit_order.push_back(u);

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    pred[v] = u;
                    q.push(v);
                }
            }
        }

        // Formatação de saída conforme especificado
        cout << "\nCaso de Teste #" << t << " - BFS(" << start << ")\n\n";

        // Impressão da ordem de início da busca em cada vértice alcançável
        for (int v : visit_order) {
            cout << "Iniciando busca em largura a partir de " << v << "\n";
        }
        cout << "\n";

        // Impressão da tabela K | D | P
        for (int i = 0; i < V; ++i) {
            cout << i << " | ";
            if (dist[i] == -1) cout << "-";
            else cout << dist[i];
            cout << " | ";
            if (pred[i] == -1) cout << "-";
            else cout << pred[i];
            cout << "\n";
        }
        cout << "\n";

        // Verificação de caminho entre O e D
        if (target >= 0 && target < V && dist[target] != -1) {
            cout << "Caminho entre " << start << " e " << target << ": ";
            vector<int> path;
            for (int curr = target; curr != -1; curr = pred[curr]) {
                path.push_back(curr);
            }
            reverse(path.begin(), path.end());
            for (int i = 0; i < (int)path.size(); ++i) {
                cout << path[i] << (i == (int)path.size() - 1 ? "" : " => ");
            }
            cout << "\n";
        } else {
            cout << "Sem caminho entre " << start << " e " << target << "\n";
        }

        // Delimitador de fim de caso de teste
        cout << "\n--------" << endl;
    }

    return 0;
}