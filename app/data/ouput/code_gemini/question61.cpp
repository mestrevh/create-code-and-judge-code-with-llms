/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x1, y1, x2, y2;

    while (std::cin >> x1 >> y1 >> x2 >> y2) {
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) {
            break;
        }

        if (x1 == x2 && y1 == y2) {
            std::cout << 0 << "\n";
        } else if (x1 == x2 || y1 == y2 || std::abs(x1 - x2) == std::abs(y1 - y2)) {
            std::cout << 1 << "\n";
        } else {
            std::cout << 2 << "\n";
        }
    }

    return 0;
}
