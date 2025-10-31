/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int H, W, P;
    std::cin >> H >> W >> P;

    int EX, EY, DX, DY;
    std::cin >> EX >> EY >> DX >> DY;

    for (int y = H; y >= 0; --y) {
        for (int x = 0; x <= W; ++x) {
            bool is_inside_box = (x >= EX && x <= DX && y >= DY && y <= EY);

            if (is_inside_box) {
                if (P == 1) {
                    std::cout << '*';
                } else {
                    bool is_on_border = (x == EX || x == DX || y == EY || y == DY);
                    if (is_on_border) {
                        std::cout << '*';
                    } else {
                        std::cout << '.';
                    }
                }
            } else {
                std::cout << '.';
            }
        }
        std::cout << '\n';
    }

    return 0;
}
