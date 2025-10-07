/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int n, soma = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            soma += i;
        }
    }
    std::cout << soma << std::endl;
    return 0;
}
