/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int valor;
    std::cin >> valor;
    int notas[] = {100, 50, 20, 10, 5, 2, 1};
    for (int nota : notas) {
        int quantidade = valor / nota;
        std::cout << quantidade << " nota(s) de R$ " << nota << ",00\n";
        valor %= nota;
    }
    return 0;
}
