/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b, c;
    if (std::cin >> a >> b >> c) {
        if (c > a) {
            std::cout << 2 * a << "\n";
        } else {
            std::cout << 3 * b << "\n";
        }
    }

    return 0;
}