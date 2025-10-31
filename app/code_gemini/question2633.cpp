/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cctype>

int main() {
    char estudante, idoso;

    std::cout << "Cliente e estudante? (s ou n)" << std::endl;
    std::cin >> estudante;

    std::cout << "Cliente e idoso? (s ou n)" << std::endl;
    std::cin >> idoso;

    estudante = tolower(estudante);
    idoso = tolower(idoso);

    if ((estudante != 's' && estudante != 'n') || (idoso != 's' && idoso != 'n')) {
        std::cout << "Entrada deve ser apenas pelas letras s ou n." << std::endl;
    } else if (estudante == 's' || idoso == 's') {
        std::cout << "Meia-entrada. Valor a ser pago: R$10,00." << std::endl;
    } else {
        std::cout << "Entrada completa. Valor a ser pago: R$20,00." << std::endl;
    }

    return 0;
}
