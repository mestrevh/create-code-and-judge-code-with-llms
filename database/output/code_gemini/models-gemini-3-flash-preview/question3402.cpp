/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double A, B, C, D;
    if (!(std::cin >> A >> B >> C >> D)) return 0;

    double x = (D - B) / (A - C);
    double y = A * x + B;

    std::cout << std::fixed << std::setprecision(2) << x << " " << y << std::endl;

    return 0;
}