/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long recursive_multiply(long long a, long long b) {
    if (b == 0) {
        return 0;
    }
    return a + recursive_multiply(a, b - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b;
    if (std::cin >> a >> b) {
        if (b < 0) {
            std::cout << recursive_multiply(-a, -b) << "\n";
        } else {
            std::cout << recursive_multiply(a, b) << "\n";
        }
    }

    return 0;
}