/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int n50 = n / 50;
    n %= 50;

    int n20 = n / 20;
    n %= 20;

    int n10 = n / 10;
    n %= 10;

    int n5 = n / 5;
    n %= 5;

    int n1 = n;

    std::cout << "Notas de 50: " << n50 << std::endl;
    std::cout << "Notas de 20: " << n20 << std::endl;
    std::cout << "Notas de 10: " << n10 << std::endl;
    std::cout << "Notas de 5: " << n5 << std::endl;
    std::cout << "Notas de 1: " << n1 << std::endl;

    return 0;
}
