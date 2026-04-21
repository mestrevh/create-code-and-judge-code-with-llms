/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long x;
    if (std::cin >> x) {
        if (x % 2 == 0) {
            std::cout << 1 << "\n";
        } else {
            std::cout << -1 << "\n";
        }
    }
    return 0;
}