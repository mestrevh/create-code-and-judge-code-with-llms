/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void extendedGcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    int x1, y1;
    extendedGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b;
    std::cin >> a >> b;
    int x, y;
    extendedGcd(a, b, x, y);
    if ((long long)a * x > (long long)b * y) {
        std::cout << x << "*" << a << " - " << -y << "*" << b << '\n';
    } else {
        std::cout << y << "*" << b << " - " << -x << "*" << a << '\n';
    }
    return 0;
}
