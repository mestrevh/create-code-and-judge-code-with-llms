/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double numbers[30];

    for (int i = 0; i < 30; ++i) {
        std::cout << "Digite um numero:" << std::endl;
        std::cin >> numbers[i];
    }

    for (int i = 1; i < 30; i += 2) {
        double num = numbers[i];
        if (num == floor(num)) {
            printf("%.1f\n", num);
        } else {
            printf("%g\n", num);
        }
    }

    return 0;
}
