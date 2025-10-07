/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int socios_atendidos = 0;
    int brindes_concedidos = 0;
    double total_arrecadado = 0.0;

    for (int i = 0; i < 5; ++i) {
        std::string tamanho_carro;
        std::string tipo_lavagem;
        std::string tipo_cliente;

        std::getline(std::cin, tamanho_carro);
        std::getline(std::cin, tipo_lavagem);
        std::getline(std::cin, tipo_cliente);

        if (tipo_cliente == "Sócio") {
            socios_atendidos++;
        }

        if (tipo_lavagem == "Com cera") {
            brindes_concedidos++;
        }
        
        if (tamanho_carro == "pequeno" || tamanho_carro == "Pequeno") {
            if (tipo_lavagem == "Sem cera") {
                if (tipo_cliente == "Sócio") {
                    total_arrecadado += 20.0;
                } else {
                    total_arrecadado += 30.0;
                }
            } else { // Com cera
                if (tipo_cliente == "Sócio") {
                    total_arrecadado += 30.0;
                } else {
                    total_arrecadado += 40.0;
                }
            }
        } else { // Grande
            if (tipo_lavagem == "Sem cera") {
                if (tipo_cliente == "Sócio") {
                    total_arrecadado += 40.0;
                } else {
                    total_arrecadado += 50.0;
                }
            } else { // Com cera
                if (tipo_cliente == "Sócio") {
                    total_arrecadado += 60.0;
                } else {
                    total_arrecadado += 80.0;
                }
            }
        }
    }

    std::cout << socios_atendidos << std::endl;
    std::cout << brindes_concedidos << std::endl;
    std::cout << std::fixed << std::setprecision(2) << total_arrecadado << std::endl;

    return 0;
}
