/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long a, b;
    std::cin >> a >> b;
    for (long long x = a; x <= b; ++x) {
        std::cout << x * x - 4 * x + 5 << "\n";
    }
    return 0;
}
