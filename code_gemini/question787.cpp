/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long fastExp(long long a, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        long long half = fastExp(a, n / 2);
        return half * half;
    } else {
        long long half = fastExp(a, (n - 1) / 2);
        return a * half * half;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long a;
    int n;
    std::cin >> a;
    std::cin >> n;
    std::cout << fastExp(a, n) << std::endl;
    return 0;
}
