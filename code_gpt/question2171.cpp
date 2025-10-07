/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int mod(int x, int y) {
    if (y == 0) return -1;
    x = std::abs(x);
    y = std::abs(y);
    if (x >= y) 
        return mod(x - y, y);
    return x;
}

int main() {
    int x, y;
    std::cin >> x >> y;
    std::cout << mod(x, y) << std::endl;
    return 0;
}
