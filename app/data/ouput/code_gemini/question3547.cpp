/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double a, b;
    std::cin >> a >> b;

    double c, d;
    std::cin >> c >> d;

    double ellipse_dim1 = 2 * a;
    double ellipse_dim2 = 2 * b;

    double ellipse_short = std::min(ellipse_dim1, ellipse_dim2);
    double ellipse_long = std::max(ellipse_dim1, ellipse_dim2);

    double rect_short = std::min(c, d);
    double rect_long = std::max(c, d);

    if (ellipse_short <= rect_short && ellipse_long <= rect_long) {
        std::cout << "Pousa, bilu\n";
    } else {
        std::cout << "Procura outro lugar, bilu\n";
    }

    return 0;
}
