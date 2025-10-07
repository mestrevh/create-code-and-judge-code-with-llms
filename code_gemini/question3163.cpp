/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

long long nth_root(long long a, int b) {
    double result = pow(static_cast<double>(a), 1.0 / static_cast<double>(b));
    return static_cast<long long>(round(result));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long a;
    int b;
    std::cin >> a >> b;
    std::cout << nth_root(a, b) << std::endl;
    return 0;
}
