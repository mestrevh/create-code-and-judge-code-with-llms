/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char sexo;
    std::cin >> sexo;
    if (sexo == 'F') {
        std::cout << "Feminino\n";
    } else if (sexo == 'M') {
        std::cout << "Masculino\n";
    } else {
        std::cout << "Sexo nao definido\n";
    }
    return 0;
}
