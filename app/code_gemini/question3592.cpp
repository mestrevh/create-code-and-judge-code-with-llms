/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char genero;
    std::cin >> genero;
    if (genero == 'M' || genero == 'm') {
        std::cout << "Masculino" << std::endl;
    } else if (genero == 'F' || genero == 'f') {
        std::cout << "Feminino" << std::endl;
    } else {
        std::cout << "Genero nao especificado" << std::endl;
    }
    return 0;
}
