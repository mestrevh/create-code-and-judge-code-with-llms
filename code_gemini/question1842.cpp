/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

double distancia(int xa, int ya, int xb, int yb) {
    double dx = xb - xa;
    double dy = yb - ya;
    return std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < n; ++i) {
        int xa, ya, xb, yb;
        std::cin >> xa >> ya >> xb >> yb;
        std::cout << distancia(xa, ya, xb, yb) << std::endl;
    }

    return 0;
}
