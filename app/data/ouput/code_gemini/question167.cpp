/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int votos_alibaba = 0;
    int votos_alcapone = 0;
    int votos_branco = 0;
    int votos_nulo = 0;
    int voto;

    while (std::cin >> voto && voto != -1) {
        if (voto == 83) {
            votos_alibaba++;
        } else if (voto == 93) {
            votos_alcapone++;
        } else if (voto == 0) {
            votos_branco++;
        } else {
            votos_nulo++;
        }
    }

    double total_validos = static_cast<double>(votos_alibaba + votos_alcapone + votos_branco);
    
    int vencedor;
    if (votos_alibaba > votos_alcapone) {
        vencedor = 83;
    } else {
        vencedor = 93;
    }

    double perc_alibaba = (static_cast<double>(votos_alibaba) / total_validos) * 100.0;
    double perc_alcapone = (static_cast<double>(votos_alcapone) / total_validos) * 100.0;

    std::cout << votos_alibaba << std::endl;
    std::cout << votos_alcapone << std::endl;
    std::cout << votos_branco << std::endl;
    std::cout << votos_nulo << std::endl;
    std::cout << vencedor << std::endl;
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << perc_alibaba << std::endl;
    std::cout << perc_alcapone << std::endl;

    return 0;
}
