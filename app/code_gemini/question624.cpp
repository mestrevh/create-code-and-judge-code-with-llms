/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long value_x = 0;
    int n, bx;
    std::cin >> n >> bx;
    for (int i = 0; i < n; ++i) {
        int digit;
        std::cin >> digit;
        value_x = value_x * bx + digit;
    }

    long long value_y = 0;
    int m, by;
    std::cin >> m >> by;
    for (int i = 0; i < m; ++i) {
        int digit;
        std::cin >> digit;
        value_y = value_y * by + digit;
    }

    if (value_x < value_y) {
        std::cout << "<\n";
    } else if (value_x > value_y) {
        std::cout << ">\n";
    } else {
        std::cout << "=\n";
    }

    return 0;
}
