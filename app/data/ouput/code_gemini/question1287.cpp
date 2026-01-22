/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long multiply(long long a, long long b) {
    if (b == 0) {
        return 0;
    }
    if (b > 0) {
        return a + multiply(a, b - 1);
    }
    return -multiply(a, -b);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b;
    while (std::cin >> a >> b) {
        std::cout << multiply(a, b) << std::endl;
    }

    return 0;
}
