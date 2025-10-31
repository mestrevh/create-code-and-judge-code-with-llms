/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void exibeMultiplos(int i, int f, int x) {
    for (int k = i; k <= f; ++k) {
        if (k % x == 0) {
            std::cout << k << std::endl;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int i, f, x;
    std::cin >> i >> f >> x;
    exibeMultiplos(i, f, x);
    return 0;
}
