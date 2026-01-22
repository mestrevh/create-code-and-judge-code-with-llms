/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <limits>

struct Passageiro {
    int poltrona;
    int idade;
    std::string nome;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<Passageiro> passageiros;
    double soma_idades = 0.0;
    int numero_passagem;

    while (std::cin >> numero_passagem && numero_passagem != -1) {
        std::string data, de, para, horario;
        int poltrona, idade;
        std::string nome;

        std::cin >> data >> de >> para >> horario >> poltrona >> idade;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, nome);

        passageiros.push_back({poltrona, idade, nome});
        soma_idades += idade;
    }

    if (passageiros.empty()) {
        return 0;
    }

    double media_idades = soma_idades / passageiros.size();

    for (const auto& p : passageiros) {
        if (p.idade > media_idades && p.poltrona % 2 == 0) {
            std::cout << p.nome << '\n';
        }
    }

    return 0;
}
