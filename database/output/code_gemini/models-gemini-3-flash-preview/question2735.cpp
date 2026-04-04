/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

struct cliente {
    int codigo;
    char nome[30];
    float credito;
};

void preencherCliente(cliente &c) {
    if (!(std::cin >> c.codigo)) return;
    if (!(std::cin >> c.nome)) return;
    if (!(std::cin >> c.credito)) return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    cliente c;
    preencherCliente(c);

    std::cout << c.codigo << "\n";
    std::cout << c.nome << "\n";
    std::cout << std::fixed << std::setprecision(2) << c.credito << "\n";

    return 0;
}