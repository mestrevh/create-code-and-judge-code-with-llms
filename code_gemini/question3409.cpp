/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <ios>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double x, y;
    double x1, y1;
    double x2, y2;

    std::cin >> x >> y;
    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;

    if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
        std::cout << "Dentro\n";
    } else {
        std::cout << "Fora\n";
    }

    return 0;
}
