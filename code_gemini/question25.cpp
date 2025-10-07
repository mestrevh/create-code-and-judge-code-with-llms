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
    for (int i = x; i <= y; ++i) {
        if (i % 10 != 0) {
            int truncated = i / 10;
            if (i % truncated == 0) {
                std::cout << i << '\n';
            }
        }
    }
    return 0;
}
