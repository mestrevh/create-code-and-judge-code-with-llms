/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    int count = 0;

    std::cout << "Digite um numero inteiro:" << std::endl;
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            if (i % 3 == 0) {
                count++;
            }
        }
    }

    if (count > 0) {
        std::cout << "Quantidade de divisores divisiveis por 3: " << count << std::endl;
    } else {
        std::cout << "O numero nao possui divisores multiplos de 3" << std::endl;
    }

    return 0;
}
