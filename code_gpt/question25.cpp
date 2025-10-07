/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;

    for (int i = x; i <= y; ++i) {
        if (i % 10 != 0) {
            int removed_digit = i / 10;
            if (removed_digit != 0 && i % removed_digit == 0) {
                std::cout << i << std::endl;
            }
        }
    }
    return 0;
}
