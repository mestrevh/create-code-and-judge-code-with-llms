/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits> // Para std::numeric_limits

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        std::vector<std::string> guests;
        guests.reserve(n);

        // Após ler um inteiro com o operador >>, o caractere de nova linha
        // (que encerra a linha onde 'n' foi digitado) permanece no buffer de entrada.
        // Precisamos consumi-lo antes da primeira chamada a std::getline,
        // que lê linhas completas, para evitar que a primeira linha lida seja vazia.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for (int i = 0; i < n; ++i) {
            std::string name;
            std::getline(std::cin, name);
            guests.push_back(name);
        }

        std::sort(guests.begin(), guests.end());

        for (const std::string& guest : guests) {
            std::cout << guest << '\n';
        }
    }

    return 0;
}