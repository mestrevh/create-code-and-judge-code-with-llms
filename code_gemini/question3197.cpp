/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int qty_2l, qty_600ml, qty_350ml;

    std::cin >> qty_2l;
    std::cin >> qty_600ml;
    std::cin >> qty_350ml;

    double total_liters = qty_2l * 2.0 + qty_600ml * 0.6 + qty_350ml * 0.35;

    std::cout << total_liters << std::endl;

    return 0;
}
