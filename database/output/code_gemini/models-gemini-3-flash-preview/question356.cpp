/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void convertToBinary(int n) {
    if (n > 1) {
        convertToBinary(n / 2);
    }
    std::cout << (n % 2) << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        convertToBinary(n);
    }

    return 0;
}