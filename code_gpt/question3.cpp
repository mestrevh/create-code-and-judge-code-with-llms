/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int n, num, soma = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        soma += num;
    }
    std::cout << soma << std::endl;
    return 0;
}
