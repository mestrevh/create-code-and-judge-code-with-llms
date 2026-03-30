/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        // Após ler o inteiro 'n' com 'std::cin >> n', o caractere de nova linha
        // ('\n') permanece no buffer de entrada. É necessário descartá-lo antes
        // de usar 'std::getline' para ler os nomes, pois 'getline' leria a linha vazia.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::vector<std::string> guests(n);
        for (int i = 0; i < n; ++i) {
            std::getline(std::cin, guests[i]);
        }

        std::sort(guests.begin(), guests.end());

        for (const std::string& name : guests) {
            std::cout << name << '\n';
        }
    }

    return 0;
}