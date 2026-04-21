/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    unsigned long long p;
    if (std::cin >> p) {
        unsigned long long v = p / 3;
        unsigned long long f = p % 3;
        std::cout << v << "\n" << f << "\n";
    }

    return 0;
}