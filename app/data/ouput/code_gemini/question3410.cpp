/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double x, y;
    std::cin >> x >> y;
    bool in_a = ((x - 1.0) * (x - 1.0) + (y - 1.0) * (y - 1.0) <= 1.0);
    bool in_b = ((x - 2.0) * (x - 2.0) + (y - 1.0) * (y - 1.0) <= 1.0);
    if (in_a && in_b) {
        std::cout << "Interior A,B\n";
    } else if (in_a) {
        std::cout << "Interior A\n";
    } else if (in_b) {
        std::cout << "Interior B\n";
    } else {
        std::cout << "Exterior\n";
    }
    return 0;
}
