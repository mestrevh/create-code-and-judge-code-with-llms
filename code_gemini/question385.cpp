/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string matricula;
    std::string matricula_menor_cre;
    float cre;

    float menor_cre = std::numeric_limits<float>::max();
    double soma_cre = 0.0;
    int contador = 0;

    while (std::cin >> matricula && matricula != "999") {
        std::cin >> cre;

        soma_cre += cre;
        contador++;

        if (cre < menor_cre) {
            menor_cre = cre;
            matricula_menor_cre = matricula;
        }
    }

    if (contador > 0) {
        double media_cre = soma_cre / contador;
        std::cout << matricula_menor_cre << std::endl;
        std::cout << std::fixed << std::setprecision(2) << media_cre << std::endl;
    }

    return 0;
}
