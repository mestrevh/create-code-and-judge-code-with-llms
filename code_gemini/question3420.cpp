/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, n;
    std::cin >> a >> b >> n;
    if (n >= 1) {
        std::cout << a << '\n';
    }
    if (n >= 2) {
        std::cout << b << '\n';
    }
    for (int i = 3; i <= n; ++i) {
        int next_term;
        if (i % 2 != 0) {
            next_term = b + a;
        } else {
            next_term = b - a;
        }
        std::cout << next_term << '\n';
        a = b;
        b = next_term;
    }
    return 0;
}
