/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <iomanip>

int calcular_nota(const std::string& resposta, const std::string& gabarito) {
    int nota = 0;
    for (size_t i = 0; i < gabarito.length(); ++i) {
        if (i < resposta.length() && resposta[i] == gabarito[i]) {
            nota++;
        }
    }
    return nota;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, std::string> submissoes;
    std::string nome, respostas;

    while (std::cin >> nome && nome != "*") {
        std::cin >> respostas;
        submissoes[nome] = respostas;
    }

    std::string gabarito;
    std::cin >> gabarito;

    if (submissoes.empty()) {
        std::cout << "Maior: 0" << std::endl;
        std::cout << "Menor: 0" << std::endl;
        std::cout << "Media: 0.00" << std::endl;
        return 0;
    }

    std::vector<int> notas;
    for (const auto& par : submissoes) {
        notas.push_back(calcular_nota(par.second, gabarito));
    }

    int maior_nota = *std::max_element(notas.begin(), notas.end());
    int menor_nota = *std::min_element(notas.begin(), notas.end());
    double soma_notas = std::accumulate(notas.begin(), notas.end(), 0.0);
    double media = soma_notas / notas.size();

    std::cout << "Maior: " << maior_nota << std::endl;
    std::cout << "Menor: " << menor_nota << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "Media: " << media << std::endl;

    return 0;
}
