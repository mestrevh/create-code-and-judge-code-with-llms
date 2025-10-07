/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <iomanip>

double calcularIndice(int desempenho, int gols, int cansaco, int entrosamento) {
    int contagemMinima = 0;
    if (desempenho == 0) {
        contagemMinima++;
    }
    if (cansaco == 0) {
        contagemMinima++;
    }
    if (entrosamento == 0) {
        contagemMinima++;
    }

    if (contagemMinima >= 2) {
        return 0.0;
    }

    return (desempenho * 2.0) + (gols * 3.5) + (cansaco * 1.5) + (entrosamento * 2.0);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<double> indices;
    const int numJogadores = 5;

    for (int i = 0; i < numJogadores; ++i) {
        std::string nome;
        int desempenho, gols, cansaco, entrosamento;

        std::getline(std::cin >> std::ws, nome);
        std::cin >> desempenho >> gols >> cansaco >> entrosamento;

        indices.push_back(calcularIndice(desempenho, gols, cansaco, entrosamento));
    }

    std::sort(indices.begin(), indices.end(), std::greater<double>());

    std::cout << std::fixed << std::setprecision(1);

    for (int i = 0; i < 3; ++i) {
        std::cout << indices[i] << std::endl;
    }

    return 0;
}
