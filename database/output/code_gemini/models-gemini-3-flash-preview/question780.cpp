/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/**
 * Problema: Pedindo um galeto
 * Especialista: Grande Mestre em Programação Competitiva
 * Estratégia: Utilizar std::list para manter a ordem de chegada e possibilitar remoções 
 * eficientes (O(1)) em qualquer posição. Um vetor de iteradores e um vetor de 
 * presença garantem acesso e verificação em O(1) para os IDs (1 a 10000).
 * Complexidade Temporal: O(N) no total, onde N é o número de operações.
 * Complexidade de Espaço: O(MAX_PEDIDO).
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    list<int> queue;
    // O problema define PEDIDO entre 1 e 10000.
    static list<int>::iterator pos[10001];
    static bool in_queue[10001];

    char op;
    while (cin >> op) {
        if (op == 'a') {
            int id;
            cin >> id;
            // Só adiciona se não estiver na fila (pedidos únicos)
            if (id >= 1 && id <= 10000 && !in_queue[id]) {
                queue.push_back(id);
                list<int>::iterator it = queue.end();
                --it;
                pos[id] = it;
                in_queue[id] = true;
            }
        } else if (op == 'r') {
            int id;
            cin >> id;
            if (id >= 1 && id <= 10000 && in_queue[id]) {
                queue.erase(pos[id]);
                in_queue[id] = false;
                cout << "removido\n";
            } else {
                cout << "falha\n";
            }
        } else if (op == 'p') {
            if (queue.empty()) {
                cout << "vazia\n";
            } else {
                bool first = true;
                for (int val : queue) {
                    if (!first) cout << " ";
                    cout << val;
                    first = false;
                }
                cout << "\n";
            }
        }
    }

    return 0;
}