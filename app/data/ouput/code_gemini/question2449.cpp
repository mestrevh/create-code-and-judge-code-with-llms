/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int caminho_atual = 0;
    double melhor_distancia = 0.0;
    int melhor_caminho = 0;
    std::string line;

    while (std::cin >> line) {
        if (line == "[") {
            caminho_atual++;
            
            double distancia = 20.0;
            int tempo_total = 0;
            bool foi_pego = false;

            while (std::cin >> line && line != "]") {
                if (foi_pego) {
                    continue;
                }

                if (line == "C") {
                    distancia += 15.0;
                } else if (line == "T") {
                    distancia += 30.0;
                } else {
                    int P = std::stoi(line);
                    int tempo_antes = tempo_total;
                    
                    if (tempo_antes >= 20) {
                        distancia -= P * 3.0;
                    } else if (tempo_antes + P > 20) {
                        int tempo_lento = 20 - tempo_antes;
                        int tempo_rapido = P - tempo_lento;
                        distancia -= (tempo_lento * 1.0 + tempo_rapido * 3.0);
                    } else {
                        distancia -= P * 1.0;
                    }
                    
                    tempo_total += P;

                    if (distancia <= 0) {
                        foi_pego = true;
                    }
                }
            }
            
            if (!foi_pego && distancia > melhor_distancia) {
                melhor_distancia = distancia;
                melhor_caminho = caminho_atual;
            }
        }
    }

    if (melhor_caminho > 0) {
        std::cout << "Tarzan fugir caminho " << melhor_caminho << std::endl;
    } else {
        std::cout << "UoooooOOooOOooooo UooooOOooOOooo" << std::endl;
    }

    return 0;
}
