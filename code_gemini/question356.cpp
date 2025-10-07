/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void decimalParaBinario(int n) {
    if (n == 0) {
        return;
    }
    decimalParaBinario(n / 2);
    std::cout << n % 2 << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0 << std::endl;
    } else {
        decimalParaBinario(n);
    }
    return 0;
}
