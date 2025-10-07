/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <numeric>
#include <limits>

struct Stock {
    std::string description;
    int quantity;
    std::deque<double> history;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, Stock> stocks;

    std::string code;
    while (std::cin >> code) {
        if (code == "FIM" || code == "fim") {
            break;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Stock new_stock;
        std::getline(std::cin, new_stock.description);
        
        double initial_price;
        std::cin >> initial_price;
        
        std::cin >> new_stock.quantity;

        new_stock.history.push_back(initial_price);
        stocks[code] = new_stock;
    }

    while (std::cin >> code) {
        if (code == "FIM" || code == "fim") {
            break;
        }

        double current_price;
        std::cin >> current_price;
        
        auto& stock = stocks[code];

        double sum = std::accumulate(stock.history.begin(), stock.history.end(), 0.0);
        double average = sum / stock.history.size();
        
        double previous_price = stock.history.back();

        if (current_price > average || current_price > previous_price) {
            std::cout << "Venda\n";
        } else {
            std::cout << "Compra\n";
        }

        stock.history.push_back(current_price);
        if (stock.history.size() > 10) {
            stock.history.pop_front();
        }
    }

    return 0;
}
