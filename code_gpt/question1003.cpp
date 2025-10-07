/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>

int main() {
    std::vector<int> sorteados(10);
    for (int &num : sorteados) {
        std::cin >> num;
    }

    int N;
    std::cin >> N;

    std::vector<std::pair<std::string, std::set<int>>> apostas(N);
    for (int i = 0; i < N; ++i) {
        std::string codigo;
        int num;
        std::cin >> codigo >> num;
        std::set<int> aposta;
        for (int j = 0; j < num; ++j) {
            int valor;
            std::cin >> valor;
            aposta.insert(valor);
        }
        apostas[i] = {codigo, aposta};
    }

    std::vector<std::string> ganhadores10, ganhadores1;

    for (const auto &aposta : apostas) {
        int acertos = 0;
        for (int num : sorteados) {
            if (aposta.second.count(num)) {
                acertos++;
            }
        }
        if (acertos == 10) {
            ganhadores10.push_back(aposta.first);
        } else if (acertos == 1) {
            ganhadores1.push_back(aposta.first);
        }
    }

    std::cout << "Faixa: 10 acertos\n";
    for (const auto &codigo : ganhadores10) {
        std::cout << codigo << "\n";
    }
    std::cout << ganhadores10.size() << " ganhadores\n\n";

    std::cout << "Faixa: 1 acerto\n";
    for (const auto &codigo : ganhadores1) {
        std::cout << codigo << "\n";
    }
    std::cout << ganhadores1.size() << " ganhador\n";

    return 0;
}
