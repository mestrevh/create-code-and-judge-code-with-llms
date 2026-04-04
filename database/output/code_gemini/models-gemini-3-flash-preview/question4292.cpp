/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <deque>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::deque<std::string> fila;
    for (int i = 0; i < n; ++i) {
        std::string mensagem;
        if (std::cin >> mensagem) {
            fila.push_back(mensagem);
        }
    }

    while (!fila.empty()) {
        std::cout << fila.front() << "\n";
        fila.pop_front();
    }

    return 0;
}