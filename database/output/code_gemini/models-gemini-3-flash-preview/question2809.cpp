/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cout << "Digite um numero:" << std::endl;
    if (std::cin >> n) {
        std::cout << "Algarismo das unidades: " << n % 10 << std::endl;
    }

    return 0;
}