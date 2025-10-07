/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string item_name;
    std::getline(std::cin, item_name);

    int years;
    std::cin >> years;

    std::transform(item_name.begin(), item_name.end(), item_name.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    double annual_price = 0.0;

    if (item_name == "mural") {
        annual_price = 200.00;
    } else if (item_name == "o coreto") {
        annual_price = 235.00;
    } else if (item_name == "meu lar") {
        annual_price = 180.00 * 0.90;
    } else if (item_name == "sua mesa") {
        annual_price = 230.00 * 0.90;
    }

    double total_price = annual_price * years;

    std::cout << std::fixed << std::setprecision(2) << total_price << std::endl;

    return 0;
}
