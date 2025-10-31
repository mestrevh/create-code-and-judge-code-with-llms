/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double temperatura;
    char sintomas;

    std::cin >> temperatura >> sintomas;

    if (sintomas != 'S' && sintomas != 'N') {
        std::cout << "Erro\n";
    } else {
        bool febre = temperatura >= 37.0;
        bool tem_sintomas = sintomas == 'S';

        if (febre && tem_sintomas) {
            std::cout << "Exames Especiais\n";
        } else if (febre && !tem_sintomas) {
            std::cout << "Exames Basicos\n";
        } else if (!febre && tem_sintomas) {
            std::cout << "Exames Basicos\n";
        } else { // !febre && !tem_sintomas
            std::cout << "Liberado\n";
        }
    }

    return 0;
}
