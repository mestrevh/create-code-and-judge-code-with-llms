/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double a1, a2, b1, b2, c1, c2;
    std::cin >> a1 >> a2;
    std::cin >> b1 >> b2;
    std::cin >> c1 >> c2;

    char m1, m2;
    std::cin >> m1 >> m2;

    int d1, d2;
    std::cin >> d1 >> d2;

    double p1 = (a1 + b1 + c1) / 3.0;
    double p2 = (a2 + b2 + c2) / 3.0;

    char f1 = 'A' + (((m1 - 'A') + d1) % 26 + 26) % 26;
    char f2 = 'A' + (((m2 - 'A') + d2) % 26 + 26) % 26;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "A pista esta na coordenada: (" << p1 << ", " << p2 << ") e o cod e: " << f1 << f2 << std::endl;

    return 0;
}
