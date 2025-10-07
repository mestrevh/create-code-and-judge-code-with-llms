/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int tonica = (n / 100) % 7;
    int terca = (n / 10) % 7;
    int quinta = n % 7;

    if (tonica == 0 && terca == 2 && quinta == 4) {
        std::cout << "Acorde do satisfaz.\n";
    } else if (tonica == 1 && terca == 3 && quinta == 5) {
        std::cout << "Acorde re satisfaz.\n";
    } else if (tonica == 2 && terca == 4 && quinta == 6) {
        std::cout << "Acorde mi satisfaz.\n";
    } else if (tonica == 3 && terca == 5 && quinta == 0) {
        std::cout << "Acorde fa satisfaz.\n";
    } else if (tonica == 4 && terca == 6 && quinta == 1) {
        std::cout << "Acorde sol satisfaz.\n";
    } else if (tonica == 5 && terca == 0 && quinta == 2) {
        std::cout << "Acorde la satisfaz.\n";
    } else if (tonica == 6 && terca == 1 && quinta == 3) {
        std::cout << "Acorde si satisfaz.\n";
    } else {
        std::cout << "Combinacao nao satisfaz.\n";
    }

    return 0;
}
