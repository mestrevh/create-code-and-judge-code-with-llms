/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }

    std::vector<int> V(n);
    std::vector<long long> W(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> V[i];
        W[i] = factorial(V[i]);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << V[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << '\n';

    for (int i = 0; i < n; ++i) {
        std::cout << W[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << '\n';

    return 0;
}
