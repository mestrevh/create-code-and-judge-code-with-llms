/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    long long idade;
    std::cin >> idade;
    long long segundos = idade * 365 * 24 * 60 * 60;
    std::cout << segundos << std::endl;
    return 0;
}
