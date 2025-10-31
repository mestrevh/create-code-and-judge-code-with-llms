/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int lotacao_maxima;
    std::cin >> lotacao_maxima;

    int pessoas_dentro = 0;
    int pessoas_fila = 0;

    std::string acao;
    std::string token;

    while (std::cin >> acao >> token) {
        if (acao == "Entraram") {
            if (token == "VIP") {
                pessoas_dentro++;
                std::cout << "1 pessoas entraram na casa. Atualmente ha " << pessoas_dentro << " pessoas no evento.\n";
            } else {
                int num_visitantes = std::stoi(token);
                if (pessoas_dentro < lotacao_maxima) {
                    int espaco_disponivel = lotacao_maxima - pessoas_dentro;
                    int entrarao = std::min(num_visitantes, espaco_disponivel);
                    
                    pessoas_dentro += entrarao;
                    std::cout << entrarao << " pessoas entraram na casa. Atualmente ha " << pessoas_dentro << " pessoas no evento.\n";

                    int foram_fila = num_visitantes - entrarao;
                    if (foram_fila > 0) {
                        pessoas_fila += foram_fila;
                        std::cout << "Infelizmente a casa esta lotada, " << foram_fila << " pessoas foram redirecionadas para a fila.\n";
                        std::cout << "A fila agora contem " << pessoas_fila << " pessoas.\n";
                    }
                } else {
                    pessoas_fila += num_visitantes;
                    std::cout << "Infelizmente a casa esta lotada, " << num_visitantes << " pessoas foram redirecionadas para a fila.\n";
                    std::cout << "A fila agora contem " << pessoas_fila << " pessoas.\n";
                }
            }
        } else if (acao == "Sairam") {
            int num_saida = std::stoi(token);
            pessoas_dentro -= num_saida;
            std::cout << num_saida << " pessoas sairam da casa. Atualmente ha " << pessoas_dentro << " pessoas no evento.\n";

            if (pessoas_fila > 0 && pessoas_dentro < lotacao_maxima) {
                int espaco_disponivel = lotacao_maxima - pessoas_dentro;
                int entrarao_fila = std::min(pessoas_fila, espaco_disponivel);
                
                if (entrarao_fila > 0) {
                    pessoas_dentro += entrarao_fila;
                    pessoas_fila -= entrarao_fila;
                    std::cout << entrarao_fila << " pessoas da fila entraram na casa.\n";

                    if (pessoas_fila == 0) {
                        std::cout << "Todos que estavam na fila de espera conseguiram entrar, atualmente nao ha fila de espera.\n";
                    } else {
                        std::cout << "A fila agora contem " << pessoas_fila << " pessoas.\n";
                    }
                }
            }
        }
        std::cout << "\n";
    }

    std::cout << "Vai Troinha, agora pede o ubii!\n";

    return 0;
}
