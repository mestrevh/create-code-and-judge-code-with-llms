/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <limits>

struct Carro {
    std::string nome;
    double desempenho;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Carro> carros;
    carros.reserve(n);
    
    double soma_desempenho = 0.0;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < n; ++i) {
        std::string nome_modelo;
        std::getline(std::cin, nome_modelo);

        double motor, suspensao, turbo;
        std::cin >> motor >> suspensao >> turbo;
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        double desempenho_atual = (motor * 5.0 + suspensao * 2.0 + turbo * 3.0) / 10.0;
        
        carros.push_back({nome_modelo, desempenho_atual});
        soma_desempenho += desempenho_atual;
    }

    if (n > 0) {
        double media_geral = soma_desempenho / n;

        for (const auto& carro : carros) {
            if (carro.desempenho >= media_geral) {
                std::cout << carro.nome << std::endl;
            }
        }
    }

    return 0;
}
