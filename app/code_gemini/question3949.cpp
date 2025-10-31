/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <set>
#include <limits>

struct Item {
    std::string name;
    double price;
};

struct Market {
    int id;
    int distance;
    std::vector<Item> items;
};

Item parse_item_line(const std::string& line) {
    Item item;
    size_t separator_pos = line.find(" - ");
    item.name = line.substr(0, separator_pos);
    item.price = std::stod(line.substr(separator_pos + 3));
    return item;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n_markets;
    std::cin >> n_markets;

    std::vector<Market> markets;
    for (int i = 0; i < n_markets; ++i) {
        Market current_market;
        current_market.id = i + 1;
        int num_items;
        std::cin >> current_market.distance >> num_items;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for (int j = 0; j < num_items; ++j) {
            std::string line;
            std::getline(std::cin, line);
            current_market.items.push_back(parse_item_line(line));
        }
        markets.push_back(current_market);
    }

    int shopping_list_size;
    std::cin >> shopping_list_size;
    std::set<std::string> shopping_list;
    for (int i = 0; i < shopping_list_size; ++i) {
        std::string item_name;
        std::cin >> item_name;
        shopping_list.insert(item_name);
    }

    int best_market_index = -1;
    int max_matches = -1;
    int min_distance = std::numeric_limits<int>::max();

    for (int i = 0; i < markets.size(); ++i) {
        int current_matches = 0;
        for (const auto& item : markets[i].items) {
            if (shopping_list.count(item.name)) {
                current_matches++;
            }
        }

        if (current_matches > max_matches) {
            max_matches = current_matches;
            min_distance = markets[i].distance;
            best_market_index = i;
        } else if (current_matches == max_matches) {
            if (markets[i].distance < min_distance) {
                min_distance = markets[i].distance;
                best_market_index = i;
            }
        }
    }

    Market& chosen_market = markets[best_market_index];
    std::cout << "Mercado: " << chosen_market.id << "\n";

    double total_cost = 0.0;
    std::vector<Item> bought_items;

    for (const auto& item : chosen_market.items) {
        if (shopping_list.count(item.name)) {
            bought_items.push_back(item);
            total_cost += item.price;
        }
    }
    
    std::cout << std::fixed << std::setprecision(2);

    for (const auto& item : bought_items) {
        std::cout << item.name << " " << item.price << "\n";
    }

    std::cout << total_cost << "\n";

    return 0;
}
