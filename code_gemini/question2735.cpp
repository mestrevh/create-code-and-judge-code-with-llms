/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

struct cliente {
    int codigo;
    char nome[30];
    float credito;
};

void preencherCliente(cliente& c) {
    std::cin >> c.codigo;
    std::cin >> c.nome;
    std::cin >> c.credito;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    cliente c1;

    preencherCliente(c1);

    std::cout << c1.codigo << std::endl;
    std::cout << c1.nome << std::endl;
    std::cout << std::fixed << std::setprecision(2) << c1.credito << std::endl;

    return 0;
}
