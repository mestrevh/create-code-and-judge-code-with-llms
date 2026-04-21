/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double R;
    if (!(std::cin >> R)) return 0;

    const double PI = 3.14159;
    double volume = (4.0 / 3.0) * PI * R * R * R;

    std::cout << "VOLUME = " << std::fixed << std::setprecision(3) << volume << "\n";

    return 0;
}