/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    double product = 1.0;
    bool has_diagonal = false;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double value;
            std::cin >> value;
            if (i == j) {
                product *= value;
                has_diagonal = true;
            }
        }
    }

    if (!has_diagonal && n > 0) product = 0.0;
    if (n <= 0) product = 0.0;

    std::cout << std::fixed << std::setprecision(1) << (n <= 0 ? 0.0 : product) << "\n";

    return 0;
}