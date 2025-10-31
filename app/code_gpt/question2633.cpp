/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    char estudante, idoso;
    std::cout << "Cliente e estudante? (s ou n)\n";
    std::cin >> estudante;
    std::cout << "Cliente e idoso? (s ou n)\n";
    std::cin >> idoso;

    if ((estudante != 's' && estudante != 'n' && estudante != 'S' && estudante != 'N') ||
        (idoso != 's' && idoso != 'n' && idoso != 'S' && idoso != 'N')) {
        std::cout << "Entrada deve ser apenas pelas letras s ou n.\n";
    } else {
        if (estudante == 's' || estudante == 'S' || idoso == 's' || idoso == 'S') {
            std::cout << "Meia-entrada. Valor a ser pago: R$10,00.\n";
        } else {
            std::cout << "Entrada completa. Valor a ser pago: R$20,00.\n";
        }
    }
    
    return 0;
}
