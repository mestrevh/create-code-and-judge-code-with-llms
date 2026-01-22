/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <string>

void solve() {
    int n;
    std::cin >> n;

    std::queue<int> fila_f;
    std::queue<int> fila_p;

    for (int i = 0; i < n; ++i) {
        char command;
        std::cin >> command;

        if (command == 'f') {
            int id;
            std::cin >> id;
            fila_f.push(id);
        } else if (command == 'p') {
            int id;
            std::cin >> id;
            fila_p.push(id);
        } else if (command == 'A') {
            if (!fila_f.empty()) {
                fila_f.pop();
            } else if (!fila_p.empty()) {
                fila_p.pop();
            }
        } else if (command == 'B') {
            if (!fila_p.empty()) {
                fila_p.pop();
            } else if (!fila_f.empty()) {
                fila_f.pop();
            }
        } else if (command == 'I') {
            if (fila_f.empty()) {
                std::cout << 0;
            } else {
                std::cout << fila_f.front();
            }
            std::cout << " ";
            if (fila_p.empty()) {
                std::cout << 0;
            } else {
                std::cout << fila_p.front();
            }
            std::cout << "\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) {
        std::cout << "Caso " << i << ":\n";
        solve();
    }

    return 0;
}
