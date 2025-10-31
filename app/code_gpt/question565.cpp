/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string numero;
    std::cout << "Digite um número com no máximo 5 algarismos: ";
    std::cin >> numero;

    if (numero.length() > 5 || !std::all_of(numero.begin(), numero.end(), ::isdigit)) {
        std::cout << "Entrada incorreta!" << std::endl;
    } else {
        std::cout << "O número possui " << numero.length() << " algarismos!" << std::endl;
    }
    return 0;
}
