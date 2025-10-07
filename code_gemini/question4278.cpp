/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double angle1, angle2;
    std::cin >> angle1 >> angle2;
    double angle3 = 180.0 - (angle1 + angle2);
    std::cout << std::setprecision(17) << angle3 << std::endl;
    return 0;
}
