/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>

int main() {
    int senha;
    std::cin >> senha;

    if (senha < 1000 || senha > 9999) {
        std::cout << "Nao pode" << std::endl;
        return 0;
    }

    std::set<char> digitos;
    int aux = senha;

    while (aux > 0) {
        char digito = aux % 10 + '0';
        if (digito == '0' || !digitos.insert(digito).second) {
            std::cout << "Nao pode" << std::endl;
            return 0;
        }
        aux /= 10;
    }

    std::cout << "Pode" << std::endl;
    return 0;
}
