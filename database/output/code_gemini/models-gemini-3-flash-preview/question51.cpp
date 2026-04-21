/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int code, quantity;
    if (!(std::cin >> code >> quantity)) return 0;

    double price = 0.0;
    switch (code) {
        case 1: price = 5.30; break;
        case 2: price = 6.00; break;
        case 3: price = 3.20; break;
        case 4: price = 2.50; break;
        default: price = 0.0; break;
    }

    double total = price * quantity;

    if (quantity >= 15 || total >= 40.0) {
        total *= 0.85;
    }

    std::cout << "R$ " << std::fixed << std::setprecision(2) << total << std::endl;

    return 0;
}