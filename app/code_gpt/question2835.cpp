/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::string texto;
    std::getline(std::cin, texto);
    std::map<char, int> frequencia;

    for (char c : texto) {
        frequencia[c]++;
    }

    std::vector<std::pair<char, int>> resultado(frequencia.begin(), frequencia.end());
    std::sort(resultado.rbegin(), resultado.rend());

    for (const auto& par : resultado) {
        std::cout << par.first << " " << par.second << std::endl;
    }

    return 0;
}
