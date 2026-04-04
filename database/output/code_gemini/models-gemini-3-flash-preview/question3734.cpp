/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

/**
 * Funcao auxiliar para imprimir o estado atual dos custos descobertos (PQ).
 * Conforme o problema, deve ser impressa a lista de tuplas (custo, node_id),
 * ordenada alfabeticamente pelo identificador do no.
 */
void print_pq(const map<char, int>& best_costs) {
    cout << "[";
    for (auto it = best_costs.begin(); it != best_costs.end(); ++it) {
        cout << "(" << it->second << ", '" << it->first << "')";
        if (next(it) != best_costs.end()) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    // Otimizacao de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s_start, s_goal;
    // Leitura do no inicial e no final
    if (!(cin >> s_start >> s_goal)) return 0;
    char start = s_start[0];
    char goal = s_goal[0];

    // Representacao do grafo (Lista de Adjacencia)
    map<char, vector<pair<char, int>>> adj;
    char u, v;
    int d;
    // Leitura das arestas ate o fim da entrada
    while (cin >> u >> v >> d) {
        adj[u].push_back({v, d});
    }

    // Estruturas para a Busca de Custo Uniforme (UCS)
    map<char, int> best_costs;      // Armazena o melhor custo conhecido para cada no
    map<char, int> discovery_time;  // Ordem de descoberta para desempate LIFO
    map<char, char> parent;         // Para reconstrucao do caminho
    set<char> visited;              // Nos cujas arestas ja foram expandidas
    int timer = 0;                  // Contador para ordem de descoberta

    // Inicializacao com o no de partida
    best_costs[start] = 0;
    discovery_time[start] = timer++;

    while (true) {
        // Imprime o estado da "fila de prioridade" (todos os nos descobertos e seus custos)
        print_pq(best_costs);

        char current = '\0';
        int min_cost = 2147483647; // Infinito (INT_MAX)
        int max_discovery = -1;

        // Seleciona o proximo no a ser expandido (o de menor custo na fronteira)
        // Desempate: Se custos iguais, o problema segue um comportamento LIFO na fronteira,
        // ou seja, o no descoberto mais recentemente tem prioridade.
        for (auto const& [node, cost] : best_costs) {
            if (visited.find(node) == visited.end()) {
                if (cost < min_cost) {
                    min_cost = cost;
                    max_discovery = discovery_time[node];
                    current = node;
                } else if (cost == min_cost) {
                    if (discovery_time[node] > max_discovery) {
                        max_discovery = discovery_time[node];
                        current = node;
                    }
                }
            }
        }

        // Se nao houver mais nos para expandir ou se o no atual for o objetivo, encerramos a busca.
        // O no objetivo e impresso mas nao e expandido.
        if (current == '\0' || current == goal) break;

        // Marca o no como visitado e expande seus vizinhos
        visited.insert(current);
        if (adj.count(current)) {
            for (auto const& edge : adj.at(current)) {
                char neighbor = edge.first;
                int weight = edge.second;
                int new_cost = min_cost + weight;

                // Se encontramos um caminho melhor para o vizinho, atualizamos o custo e o pai
                if (best_costs.find(neighbor) == best_costs.end() || new_cost < best_costs[neighbor]) {
                    best_costs[neighbor] = new_cost;
                    parent[neighbor] = current;
                    // Registramos o tempo da primeira descoberta para fins de desempate
                    if (discovery_time.find(neighbor) == discovery_time.end()) {
                        discovery_time[neighbor] = timer++;
                    }
                }
            }
        }
    }

    // Reconstrucao do caminho do no final ate o inicial usando os ponteiros de parentesco
    vector<char> path;
    char curr = goal;
    // Assume-se que o caminho existe conforme o enunciado
    while (curr != start) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    // Saida final: O percurso realizado formatado como uma lista Python
    cout << "[";
    for (int i = 0; i < (int)path.size(); ++i) {
        cout << "'" << path[i] << "'" << (i == (int)path.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    return 0;
}