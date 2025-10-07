/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double a, b, e;
    int c, d;

    std::cin >> a >> b >> c >> d >> e;

    double total_money = a + b;
    double base_price = d * e;
    double final_price;

    if (c == 0) {
        final_price = base_price * 0.95;
    } else {
        final_price = base_price * 0.85;
    }

    if (final_price <= total_money) {
        std::cout << "Faz um Ifood!\n";
    } else {
        std::cout << "pede menos que as esfihas nao vao acabar hoje!\n";
    }

    return 0;
}
