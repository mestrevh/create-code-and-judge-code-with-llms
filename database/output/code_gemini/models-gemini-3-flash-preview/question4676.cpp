/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Função para imprimir o estado atual da fila circular.
 * De acordo com as regras, um elemento está presente nos índices:
 * - Se head < tail: [head, tail - 1]
 * - Se head > tail: [head, SIZE - 1] e [0, tail - 1]
 * - Se head == tail: Fila vazia
 */
void printQueue(const vector<int>& q, int head, int tail, int SIZE) {
    for (int i = 0; i < SIZE; ++i) {
        bool present = false;
        if (head < tail) {
            if (i >= head && i < tail) {
                present = true;
            }
        } else if (head > tail) {
            if (i >= head || i < tail) {
                present = true;
            }
        }
        
        if (present) {
            cout << q[i] << " ";
        } else {
            cout << "- ";
        }
    }
    cout << "\n";
}

int main() {
    // Otimização de I/O padrão C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int SIZE;
    if (!(cin >> SIZE)) return 0;

    // A fila é representada por um array de tamanho SIZE.
    // Usamos um espaço vazio reservado para distinguir Cheia de Vazia.
    vector<int> q(SIZE);
    int head = 0; // Índice do primeiro elemento
    int tail = 0; // Índice da próxima posição livre

    string cmd;
    while (cin >> cmd) {
        if (cmd == "F") {
            cout << "Saindo...\n";
            break;
        } else if (cmd == "E") {
            int val;
            cin >> val;
            // Condição de Fila Cheia: o próximo tail seria o head
            if (((tail + 1) % SIZE) == head) {
                cout << "Fila cheia\n";
            } else {
                q[tail] = val;
                tail = (tail + 1) % SIZE;
                printQueue(q, head, tail, SIZE);
            }
        } else if (cmd == "D") {
            // Condição de Fila Vazia: head e tail no mesmo lugar
            if (head == tail) {
                cout << "Fila vazia\n";
            } else {
                int removedValue = q[head];
                cout << removedValue << "\n";
                head = (head + 1) % SIZE;
                printQueue(q, head, tail, SIZE);
            }
        }
    }

    return 0;
}
