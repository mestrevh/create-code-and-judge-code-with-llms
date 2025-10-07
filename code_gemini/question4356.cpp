/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }
    std::vector<int> factors;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    std::sort(factors.begin(), factors.end());
    for (int factor : factors) {
        std::cout << factor << " ";
    }
    std::cout << std::endl;
    return 0;
}

