/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int idade;
    std::cin >> idade;
    if (idade < 5) {
        std::cout << "Idade invalida.\n";
    } else if (idade <= 7) {
        std::cout << "Infantil A\n";
    } else if (idade <= 10) {
        std::cout << "Infantil B\n";
    } else if (idade <= 13) {
        std::cout << "Juvenil A\n";
    } else if (idade <= 17) {
        std::cout << "Juvenil B\n";
    } else if (idade <= 40) {
        std::cout << "Adulto\n";
    } else {
        std::cout << "Master\n";
    }
    return 0;
}
