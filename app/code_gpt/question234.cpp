/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    int x, y;
    std::cin >> x >> y;
    if (x > y) std::swap(x, y);
    
    for (int i = x + 1; i < y; ++i) {
        if (i % 5 == 2 || i % 5 == 3) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}
