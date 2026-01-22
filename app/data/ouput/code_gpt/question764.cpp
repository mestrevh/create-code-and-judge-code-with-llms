/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

std::vector<long long> seq(101, 0);

long long fibonacci(int n) {
    if (n <= 3) return 1;
    if (seq[n] != 0) return seq[n];
    seq[n] = fibonacci(n - 1) + fibonacci(n - 2) + fibonacci(n - 3);
    return seq[n];
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cout << fibonacci(i) << std::endl;
    }
    return 0;
}
