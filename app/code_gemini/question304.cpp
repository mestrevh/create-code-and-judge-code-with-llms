/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int N;
    std::cin >> N;

    std::cout << N << std::endl;

    int notas[] = {100, 50, 20, 10, 5, 2, 1};
    int valor_restante = N;

    for (int nota : notas) {
        int quantidade = valor_restante / nota;
        std::cout << quantidade << " nota(s) de R$ " << nota << ",00" << std::endl;
        valor_restante %= nota;
    }

    return 0;
}
