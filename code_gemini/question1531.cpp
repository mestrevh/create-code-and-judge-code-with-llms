/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string time;
    std::cin >> time;

    if (time == "GSW" || time == "HOU" || time == "CLE" || time == "BOS") {
        std::string nome_jogador;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, nome_jogador);

        int tentados_2pts, convertidos_2pts;
        int tentados_3pts, convertidos_3pts;
        std::cin >> tentados_2pts >> convertidos_2pts >> tentados_3pts >> convertidos_3pts;

        int pontos_totais = (convertidos_2pts * 2) + (convertidos_3pts * 3);
        
        double percentual_2pts = 0.0;
        if (tentados_2pts > 0) {
            percentual_2pts = static_cast<double>(convertidos_2pts) / tentados_2pts * 100.0;
        }

        double percentual_3pts = 0.0;
        if (tentados_3pts > 0) {
            percentual_3pts = static_cast<double>(convertidos_3pts) / tentados_3pts * 100.0;
        }
        
        bool is_doing_well = (pontos_totais > 30) ||
                             (percentual_2pts > 50 && tentados_2pts > 10) ||
                             (percentual_3pts > 40 && tentados_3pts > 7);

        if (is_doing_well) {
            std::cout << "O time " << time << " estah jogando, e " << nome_jogador << " estah indo bem." << std::endl;
        } else {
            std::cout << "O time " << time << " estah jogando, mas " << nome_jogador << " nao estah indo bem." << std::endl;
        }

    } else {
        std::cout << "Nenhum time de interesse jogando." << std::endl;
    }

    return 0;
}
