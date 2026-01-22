/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

bool check(int pX, int pY, int w1, int h1, int w2, int h2) {
    if (w1 + w2 <= pX && std::max(h1, h2) <= pY) return true;
    if (h1 + h2 <= pY && std::max(w1, w2) <= pX) return true;
    if (w1 + w2 <= pY && std::max(h1, h2) <= pX) return true;
    if (h1 + h2 <= pX && std::max(w1, w2) <= pY) return true;
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int X, Y, L1, H1, L2, H2;
    std::cin >> X >> Y >> L1 >> H1 >> L2 >> H2;

    bool possible =
        check(X, Y, L1, H1, L2, H2) ||
        check(X, Y, H1, L1, L2, H2) ||
        check(X, Y, L1, H1, H2, L2) ||
        check(X, Y, H1, L1, H2, L2);

    if (possible) {
        std::cout << 'S' << '\n';
    } else {
        std::cout << 'N' << '\n';
    }

    return 0;
}
