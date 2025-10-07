/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long Fatorial(int n) {
    if (n == 0) {
        return 1;
    }
    long long resultado = 1;
    for (int i = 1; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::cout << Fatorial(n) << std::endl;
    return 0;
}
