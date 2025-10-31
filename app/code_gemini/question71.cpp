/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<int, int> stock;
    int code, quantity;

    while (true) {
        std::cin >> code;
        if (code == 9999) {
            break;
        }
        std::cin >> quantity;
        stock[code] = quantity;
    }

    int client_id, requested_code, requested_quantity;
    while (true) {
        std::cin >> client_id;
        if (client_id == 9999) {
            break;
        }
        std::cin >> requested_code >> requested_quantity;

        if (stock.count(requested_code) && stock[requested_code] >= requested_quantity) {
            stock[requested_code] -= requested_quantity;
            std::cout << "OK\n";
        } else {
            std::cout << "ESTOQUE INSUFICIENTE\n";
        }
    }

    for (const auto& item : stock) {
        std::cout << item.first << " " << item.second << "\n";
    }

    return 0;
}
