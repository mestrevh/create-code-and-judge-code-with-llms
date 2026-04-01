/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    switch (n) {
        case 1:
            std::cout << "Domingo\n";
            break;
        case 2:
            std::cout << "Segunda\n";
            break;
        case 3:
            std::cout << "Terca\n";
            break;
        case 4:
            std::cout << "Quarta\n";
            break;
        case 5:
            std::cout << "Quinta\n";
            break;
        case 6:
            std::cout << "Sexta\n";
            break;
        case 7:
            std::cout << "Sabado\n";
            break;
        default:
            std::cout << "valor inválido\n";
            break;
    }

    return 0;
}