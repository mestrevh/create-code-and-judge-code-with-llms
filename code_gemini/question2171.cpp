/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int MOD(int x, int y) {
    if (y == 0) {
        return -1;
    }

    int abs_x = std::abs(x);
    int abs_y = std::abs(y);

    if (abs_x < abs_y) {
        return abs_x;
    } else {
        return MOD(abs_x - abs_y, abs_y);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, y;
    std::cin >> x >> y;
    std::cout << MOD(x, y) << std::endl;
    return 0;
}
