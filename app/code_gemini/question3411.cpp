/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double percurso;
    char tipo;

    std::cin >> percurso >> tipo;

    switch (tipo) {
        case 'A':
            std::cout << std::fixed << std::setprecision(2) << percurso / 12.0 << std::endl;
            break;
        case 'B':
            std::cout << std::fixed << std::setprecision(2) << percurso / 9.0 << std::endl;
            break;
        case 'C':
            std::cout << std::fixed << std::setprecision(2) << percurso / 8.0 << std::endl;
            break;
        default:
            std::cout << "Tipo inválido!" << std::endl;
            break;
    }

    return 0;
}
