/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

int toDecimal(const std::vector<int>& digits, int base) {
    int value = 0;
    for (int i = 0; i < digits.size(); ++i) {
        value += digits[i] * std::pow(base, digits.size() - 1 - i);
    }
    return value;
}

int main() {
    int n, bx, m, by;
    std::cin >> n >> bx;
    std::vector<int> x(n);
    for (int i = 0; i < n; ++i) std::cin >> x[i];
    
    std::cin >> m >> by;
    std::vector<int> y(m);
    for (int i = 0; i < m; ++i) std::cin >> y[i];

    int X = toDecimal(x, bx);
    int Y = toDecimal(y, by);

    if (X < Y) std::cout << "<" << std::endl;
    else if (X > Y) std::cout << ">" << std::endl;
    else std::cout << "=" << std::endl;

    return 0;
}
