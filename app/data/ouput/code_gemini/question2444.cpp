/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int vida_oponente;
    int estamina_tarzan;
    std::string arma;

    std::cin >> vida_oponente;
    std::cin >> estamina_tarzan;
    std::cin >> arma;

    int dano = 0;
    int custo_estamina = 0;

    if (arma == "pedra") {
        dano = 15;
        custo_estamina = 13;
    } else if (arma == "graveto") {
        dano = 10;
        custo_estamina = 8;
    }

    if (dano == 0) {
        std::cout << "Tarzan nao consegue lutar sem armas... Ele foi capturado" << std::endl;
    } else {
        while (vida_oponente > 0 && estamina_tarzan > 0) {
            vida_oponente -= dano;
            estamina_tarzan -= custo_estamina;
        }

        if (vida_oponente <= 0) {
            std::cout << "Tarzan venceu o invasor e o expulsou de sua floresta" << std::endl;
        } else {
            std::cout << "Tarzan nao foi capaz de derrotar o invasor... Ele foi capturado" << std::endl;
        }
    }

    return 0;
}
