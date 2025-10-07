/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double price;
    int quantity;
    double total_value = 0.0;
    int total_exchanged_items = 0;

    std::cout << "Insira a quantidade e valor de cada presente:\n";

    for (int i = 0; i < 6; ++i) {
        std::cin >> price >> quantity;
        if (quantity > 1) {
            int items_to_exchange = quantity - 1;
            total_exchanged_items += items_to_exchange;
            total_value += items_to_exchange * price;
        }
    }

    std::cout << "Numero de presentes a serem trocados: " << total_exchanged_items << "\n";

    if (total_value >= 800.0) {
        std::cout << "Voce PODERA adquirir o ar condicionado com as trocas\n";
    } else {
        std::cout << "Voce NAO PODERA adquirir o ar condicionado com as trocas\n";
    }

    return 0;
}
