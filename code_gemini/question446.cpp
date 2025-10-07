/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int paid_brushes = (n / 3) * 2 + (n % 3);
    double total_cost = paid_brushes * 2.20;
    std::cout << std::fixed << std::setprecision(2) << total_cost << std::endl;
    return 0;
}
