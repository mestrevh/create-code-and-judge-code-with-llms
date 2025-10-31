/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, y;
    std::cin >> x >> y;
    if (x <= y) {
        for (int i = x; i <= y; ++i) {
            std::cout << i << '\n';
        }
    } else {
        for (int i = x; i >= y; --i) {
            std::cout << i << '\n';
        }
    }
    return 0;
}
