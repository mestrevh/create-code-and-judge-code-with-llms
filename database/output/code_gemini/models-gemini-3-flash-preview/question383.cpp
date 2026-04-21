/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b, c;
    if (!(std::cin >> a >> b >> c)) return 0;

    double average = (static_cast<double>(a) + b + c) / 3.0;

    std::cout << std::scientific << std::setprecision(2) << average << "\n";

    return 0;
}