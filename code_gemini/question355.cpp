/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void imprimirParesDecrescente(int n) {
    if (n < 0) {
        return;
    }
    std::cout << n << std::endl;
    imprimirParesDecrescente(n - 2);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;

    if (n % 2 != 0) {
        n--;
    }

    imprimirParesDecrescente(n);

    return 0;
}
