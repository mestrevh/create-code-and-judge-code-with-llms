/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

int main() {
    std::string item, max_item;
    float price, total = 0, max_price = 0;

    while (true) {
        std::getline(std::cin, item);
        if (item == "FIM" || item == "fim") break;
        std::cin >> price;
        std::cin.ignore();

        total += price;
        if (price > max_price) {
            max_price = price;
            max_item = item;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << total << std::endl;
    std::transform(max_item.begin(), max_item.end(), max_item.begin(), ::toupper);
    std::cout << max_item << std::endl;

    return 0;
}
