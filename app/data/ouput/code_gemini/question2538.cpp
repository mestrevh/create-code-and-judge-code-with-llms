/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int quantity;
    std::cin >> quantity;
    std::cout << "Digite a quantidade de macas:" << std::endl;
    double price;
    if (quantity < 12) {
        price = 0.30;
    } else {
        price = 0.25;
    }
    double total_cost = quantity * price;
    std::cout << "Valor total: R$ " << total_cost << std::endl;
    return 0;
}
