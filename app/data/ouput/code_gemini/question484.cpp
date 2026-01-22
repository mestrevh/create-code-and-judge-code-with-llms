/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int macacos_count = 0;
    int tigres_count = 0;
    double tigres_peso_total = 0.0;
    int cobras_venezuela_count = 0;

    std::string tipo;
    double peso;
    std::string pais_origem;
    std::string comando;

    while (true) {
        std::cin >> tipo;
        std::cin >> peso;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, pais_origem);

        if (tipo == "macaco") {
            macacos_count++;
        } else if (tipo == "tigre") {
            tigres_count++;
            tigres_peso_total += peso;
        } else if (tipo == "cobra" && pais_origem == "Venezuela") {
            cobras_venezuela_count++;
        }

        std::cin >> comando;
        std::transform(comando.begin(), comando.end(), comando.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        if (comando == "parar") {
            break;
        }
    }

    double media_peso_tigres = 0.0;
    if (tigres_count > 0) {
        media_peso_tigres = tigres_peso_total / tigres_count;
    }

    std::cout << macacos_count << std::endl;
    std::cout << std::fixed << std::setprecision(2) << media_peso_tigres << std::endl;
    std::cout << cobras_venezuela_count << std::endl;

    return 0;
}
