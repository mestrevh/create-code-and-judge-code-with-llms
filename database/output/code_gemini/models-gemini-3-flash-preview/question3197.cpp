/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long q2L, q600ml, q350ml;
    if (std::cin >> q2L >> q600ml >> q350ml) {
        double total = (q2L * 2.0) + (q600ml * 0.6) + (q350ml * 0.35);
        std::cout << std::fixed << std::setprecision(1) << total << "\n";
    }
    return 0;
}