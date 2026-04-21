/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    while (std::cin >> n) {
        std::cout << "Digite um numero:" << "\n";
        if (n % 2 == 0) {
            std::cout << "O numero digitado e par" << "\n";
        } else {
            std::cout << "O numero digitado e impar" << "\n";
        }
    }

    return 0;
}