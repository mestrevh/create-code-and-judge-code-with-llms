/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    int n;
    while (std::cin >> n) {
        if (n < 1000 || n > 9999) break;
        int a = n / 100; // Parte dos 2 primeiros dígitos
        int b = n % 100; // Parte dos 2 últimos dígitos
        int sum = a + b;
        if (sum * sum == n) {
            std::cout << "propriedade do 3025!" << std::endl;
        } else {
            std::cout << "numero comum" << std::endl;
        }
    }
    return 0;
}
