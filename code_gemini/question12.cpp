/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::map<int, double> menu;
    for (int i = 0; i < n; ++i) {
        int code;
        std::string description;
        double price;

        std::cin >> code;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, description);
        std::cin >> price;

        menu[code] = price;
    }

    double total_bill = 0.0;
    int order_code;
    int quantity;

    while (std::cin >> order_code && order_code != 0) {
        std::cin >> quantity;

        if (quantity > 0 && menu.count(order_code) > 0) {
            total_bill += menu[order_code] * quantity;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << total_bill << std::endl;

    return 0;
}
