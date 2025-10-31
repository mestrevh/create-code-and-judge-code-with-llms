/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long laranjas_casa, bananas_casa, ovos_casa, leite_casa_ml;
    std::cin >> laranjas_casa >> bananas_casa >> ovos_casa >> leite_casa_ml;

    if (laranjas_casa < 0 || bananas_casa < 0 || ovos_casa < 0 || leite_casa_ml < 0) {
        std::cout << "lurn maf :(\n";
        return 0;
    }

    long long laranjas_comprar = 0;
    long long bananas_comprar = 0;
    long long ovos_comprar = 0;
    long long leite_comprar_ml = 0;

    // Regra Laranjas
    if (laranjas_casa == 0) {
        laranjas_comprar = bananas_casa * bananas_casa;
    }

    // Regra Bananas
    if (laranjas_comprar > 0) {
        bananas_comprar = 2;
    }

    // Regra Ovos
    long long total_bananas = bananas_casa + bananas_comprar;
    if (total_bananas > ovos_casa) {
        long long ovos_necessarios = laranjas_comprar - ovos_casa;
        if (ovos_necessarios > 0) {
            ovos_comprar = ovos_necessarios;
        }
    }

    // Regra Leite
    if (ovos_comprar > 0) {
        if (leite_casa_ml < 2000) {
            leite_comprar_ml = 2000 - leite_casa_ml;
        }
    } else {
        leite_comprar_ml = 500;
    }

    std::cout << laranjas_comprar << " laranjas\n";
    std::cout << bananas_comprar << " bananas\n";
    std::cout << ovos_comprar << " ovos\n";
    std::cout << leite_comprar_ml << " mL de leite\n";

    return 0;
}
