/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }

    std::map<std::string, int> contagem_votos;
    for (int i = 0; i < n; ++i) {
        std::string artista;
        std::cin >> artista;
        contagem_votos[artista]++;
    }

    int max_votos = 0;
    for (const auto& par : contagem_votos) {
        if (par.second > max_votos) {
            max_votos = par.second;
        }
    }

    std::vector<std::string> vencedores;
    for (const auto& par : contagem_votos) {
        if (par.second == max_votos) {
            vencedores.push_back(par.first);
        }
    }

    if (vencedores.size() == 1) {
        std::cout << "As pessoas estao esperando por " << vencedores[0] << ".\n";
    } else {
        std::sort(vencedores.begin(), vencedores.end());
        std::cout << "Houve um empate entre: ";
        for (size_t i = 0; i < vencedores.size(); ++i) {
            std::cout << vencedores[i];
            if (i < vencedores.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
