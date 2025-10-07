/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Passageiro {
    int numero;
    std::string data, origem, destino, horario;
    int poltrona, idade;
    std::string nome;
};

int main() {
    std::vector<Passageiro> passageiros;
    Passageiro p;

    while (true) {
        std::cin >> p.numero;
        if (p.numero == -1) break;
        std::cin >> p.data >> p.origem >> p.destino >> p.horario >> p.poltrona >> p.idade;
        std::getline(std::cin >> std::ws, p.nome);
        passageiros.push_back(p);
    }

    double somaIdades = 0;
    int count = 0;

    for (const auto& pass : passageiros) {
        somaIdades += pass.idade;
        count++;
    }
    
    double mediaIdade = somaIdades / count;

    for (const auto& pass : passageiros) {
        if (pass.idade > mediaIdade && pass.poltrona % 2 == 0) {
            std::cout << pass.nome << std::endl;
        }
    }

    return 0;
}
