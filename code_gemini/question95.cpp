/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct Item {
    std::string name;
    double price;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double money;
    std::cin >> money;

    int n;
    std::cin >> n;

    std::vector<Item> all_items(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> all_items[i].name >> all_items[i].price;
    }

    std::sort(all_items.begin(), all_items.end(), [](const Item& a, const Item& b) {
        return a.price < b.price;
    });

    std::vector<Item> bought_items;
    for (const auto& item : all_items) {
        if (money >= item.price) {
            money -= item.price;
            bought_items.push_back(item);
        }
    }

    std::sort(bought_items.begin(), bought_items.end(), [](const Item& a, const Item& b) {
        return a.name < b.name;
    });

    std::cout << std::fixed << std::setprecision(2);

    for (const auto& item : bought_items) {
        std::cout << item.name << " " << item.price << '\n';
    }

    std::cout << money << '\n';

    return 0;
}
