/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << "Digite a quantidade de cavalos" << std::endl;

    long long n;
    if (std::cin >> n) {
        long long ferraduras = n * 4;
        std::cout << "Sao necessarias " << ferraduras << " ferraduras" << std::endl;
    }

    return 0;
}