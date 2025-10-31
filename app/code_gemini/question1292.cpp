/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    long long concentration = fibonacci(n);
    if (concentration == 0) {
        std::cout << "O antidoto nao e necessario" << std::endl;
    } else {
        std::cout << concentration << " mg/L" << std::endl;
    }
    return 0;
}
