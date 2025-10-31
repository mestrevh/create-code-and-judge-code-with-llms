/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int L, C, H, l, c, h;
    std::cin >> L >> C >> H >> l >> c >> h;
    if (h <= H && std::min(l, c) <= std::min(L, C) && std::max(l, c) <= std::max(L, C)) {
        std::cout << "SIM\n";
    } else {
        std::cout << "NAO\n";
    }
    return 0;
}
