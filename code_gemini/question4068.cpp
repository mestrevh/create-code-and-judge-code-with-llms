/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

struct Peca {
    int valor;
    int performance;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long dinheiro;
    int num_pecas;
    std::cin >> dinheiro >> num_pecas;

    std::vector<Peca> motores;
    std::vector<Peca> rodas;
    std::vector<Peca> latarias;

    for (int i = 0; i < num_pecas; ++i) {
        std::string tipo;
        int valor, performance;
        std::cin >> tipo >> valor >> performance;
        if (tipo == "Motor") {
            motores.push_back({valor, performance});
        } else if (tipo == "Roda") {
            rodas.push_back({valor, performance});
        } else if (tipo == "Lataria") {
            latarias.push_back({valor, performance});
        }
    }

    if (motores.empty() || rodas.empty() || latarias.empty()) {
        std::cout << "Nao foi possivel construir uma caranga...\n";
        return 0;
    }

    long long best_performance = -1;
    long long best_cost = -1;

    for (const auto& motor : motores) {
        for (const auto& roda : rodas) {
            for (const auto& lataria : latarias) {
                long long current_cost = (long long)motor.valor + roda.valor + lataria.valor;
                
                if (current_cost <= dinheiro) {
                    long long current_performance = (long long)motor.performance + roda.performance + lataria.performance;
                    
                    if (current_performance > best_performance) {
                        best_performance = current_performance;
                        best_cost = current_cost;
                    } else if (current_performance == best_performance) {
                        if (current_cost < best_cost) {
                            best_cost = current_cost;
                        }
                    }
                }
            }
        }
    }

    if (best_performance == -1) {
        std::cout << "Nao foi possivel construir uma caranga...\n";
    } else {
        std::cout << "Minha nave tem uma performance de " << best_performance << " pontos\n";
        long long dinheiro_restante = dinheiro - best_cost;
        if (dinheiro_restante > 0) {
            std::cout << "E ainda me sobraram " << dinheiro_restante << " mangos!\n";
        }
    }

    return 0;
}
