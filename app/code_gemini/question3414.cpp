/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b;
    std::cin >> a >> b;
    int diff = std::abs(a - b);
    if (diff == 1) {
        std::cout << 2 << "\n";
    } else {
        int q = diff / 3;
        int rem = diff % 3;
        if (rem == 0) {
            std::cout << q << "\n";
        } else {
            std::cout << q + 1 << "\n";
        }
    }
    return 0;
}
