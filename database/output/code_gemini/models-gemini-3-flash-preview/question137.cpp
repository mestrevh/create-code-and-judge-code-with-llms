/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estudo de conectividade forte em grafos orientados e 2-aresta-conectividade em grafos não-orientados.
// Estrutura para representar arestas e lidar com múltiplas arestas entre os mesmos nós.
struct Edge {
    int to;
    int id;
};

// Variáveis globais para armazenamento e algoritmos de grafos.
int N, M;
vector<int> adj_dir[1005], adj_rev[1005];
vector<Edge> adj_undir[1005];
int edge_type[100005];
int tin[1005], low[1005], timer;
bool has_t1_bridge;
bool vis[1005];
int visited_count;

// DFS para verificar conectividade forte no grafo atual.
void dfs_sc_dir(int u) {
    vis[u] = true;
    visited_count++;
    for (int v : adj_dir[u]) {
        if (!vis[v]) dfs_sc_dir(v);
    }
}

void dfs_sc_rev(int u) {
    vis[u] = true;
    visited_count++;
    for (int v : adj_rev[u]) {
        if (!vis[v]) dfs_sc_rev(v);
    }
}

// DFS para verificar conectividade simples (grafo não-orientado subjacente).
void dfs_undir(int u) {
    vis[u] = true;
    visited_count++;
    for (auto& e : adj_undir[u]) {
        if (!vis[e.to]) dfs_undir(e.to);
    }
}

// Algoritmo de Tarjan para encontrar pontes em um grafo não-orientado.
// Se uma ponte for identificada como originalmente de mão única (T=1),
// o decreto só poderá ser cumprido convertendo-a para mão dupla (T=2).
void find_bridges(int u, int p_idx) {
    tin[u] = low[u] = timer++;
    for (auto& e : adj_undir[u]) {
        if (e.id == p_idx) continue;
        if (tin[e.to] == -1) {
            find_bridges(e.to, e.id);
            low[u] = min(low[u], low[e.to]);
            if (low[e.to] > tin[u]) {
                if (edge_type[e.id] == 1) has_t1_bridge = true;
            }
        } else {
            low[u] = min(low[u], tin[e.to]);
        }
    }
}

int main() {
    // Otimização de I/O padrão em C++ para maratona de programação.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N >> M && (N != -1 || M != -1)) {
        // Limpeza de estruturas de dados para cada caso de teste.
        for (int i = 1; i <= N; i++) {
            adj_dir[i].clear();
            adj_rev[i].clear();
            adj_undir[i].clear();
        }

        for (int i = 0; i < M; i++) {
            int u, v, t;
            cin >> u >> v >> t;
            // A primeira rua fornecida é interditada (ignorada).
            if (i == 0) continue;
            
            edge_type[i] = t;
            // Armazenamento para o grafo não-orientado subjacente.
            adj_undir[u].push_back({v, i});
            adj_undir[v].push_back({u, i});
            
            // Construção do grafo orientado com as direções atuais.
            if (t == 1) { // Mão única: A -> B
                adj_dir[u].push_back(v);
                adj_rev[v].push_back(u);
            } else { // Mão dupla: A <-> B
                adj_dir[u].push_back(v);
                adj_dir[v].push_back(u);
                adj_rev[u].push_back(v);
                adj_rev[v].push_back(u);
            }
        }

        // Casos com apenas um cruzamento são trivialmente conexos.
        if (N <= 1) {
            cout << "-" << endl;
            continue;
        }

        // Passo 1: Verificar se o grafo já é fortemente conexo (-).
        bool sc = false;
        visited_count = 0;
        for (int i = 1; i <= N; i++) vis[i] = false;
        dfs_sc_dir(1);
        if (visited_count == N) {
            visited_count = 0;
            for (int i = 1; i <= N; i++) vis[i] = false;
            dfs_sc_rev(1);
            if (visited_count == N) sc = true;
        }

        if (sc) {
            cout << "-" << endl;
        } else {
            // Passo 2: Verificar conectividade do grafo não-orientado subjacente (*).
            visited_count = 0;
            for (int i = 1; i <= N; i++) vis[i] = false;
            dfs_undir(1);
            if (visited_count < N) {
                cout << "*" << endl;
            } else {
                // Passo 3: Diferenciar entre inversão (1) e conversão para mão dupla (2).
                // Robbins' Theorem estendido: Um grafo pode ser orientado fortemente se e somente se
                // é 2-aresta-conectado. Pontes existentes devem ser bidirecionais (T=2).
                has_t1_bridge = false;
                timer = 0;
                for (int i = 1; i <= N; i++) tin[i] = -1;
                find_bridges(1, -1);
                
                if (has_t1_bridge) {
                    // Existe uma ponte de mão única que impede a conectividade forte a menos que seja duplicada.
                    cout << "2" << endl;
                } else {
                    // Todas as pontes são bidirecionais; ciclos podem ser reorientados.
                    cout << "1" << endl;
                }
            }
        }
    }

    return 0;
}
