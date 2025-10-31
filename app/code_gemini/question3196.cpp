/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int preco;
    std::cin >> preco;
    int notas[] = {100, 50, 20, 10, 5, 2, 1};
    for (int nota : notas) {
        int quantidade = preco / nota;
        std::cout << quantidade << "\n";
        preco %= nota;
    }
    return 0;
}
