/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, y;
    std::cin >> x >> y;

    if (x > y) {
        std::swap(x, y);
    }

    for (int i = x + 1; i < y; ++i) {
        if (i % 5 == 2 || i % 5 == 3) {
            std::cout << i << "\n";
        }
    }

    return 0;
}
