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
        std::cout << "Informe a quantidade de cavalos existentes no haras:" << std::endl;
        std::cout << "Numero de ferraduras a serem compradas: " << n * 4 << std::endl;
    }
    return 0;
}