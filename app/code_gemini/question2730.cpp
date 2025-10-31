/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void imprimirAsteriscos(int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << '*';
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    imprimirAsteriscos(n);
    return 0;
}
