/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int mes;
    std::cin >> mes;
    switch (mes) {
        case 1:
            std::cout << "janeiro\n";
            break;
        case 2:
            std::cout << "fevereiro\n";
            break;
        case 3:
            std::cout << "marco\n";
            break;
        case 4:
            std::cout << "abril\n";
            break;
        case 5:
            std::cout << "maio\n";
            break;
        case 6:
            std::cout << "junho\n";
            break;
        case 7:
            std::cout << "julho\n";
            break;
        case 8:
            std::cout << "agosto\n";
            break;
        case 9:
            std::cout << "setembro\n";
            break;
        case 10:
            std::cout << "outubro\n";
            break;
        case 11:
            std::cout << "novembro\n";
            break;
        case 12:
            std::cout << "dezembro\n";
            break;
        default:
            std::cout << "invalido\n";
            break;
    }
    return 0;
}
