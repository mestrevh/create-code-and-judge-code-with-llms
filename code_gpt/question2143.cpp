/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main() {
    vector<vector<string>> slots(10);
    vector<double> prices(10);
    map<string, pair<int, double>> inventory;

    for (int i = 0; i < 10; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string item;
        while (ss >> item) {
            slots[i].push_back(item);
            if (inventory.find(item) == inventory.end()) {
                inventory[item] = {i, 0.0};
            }
        }
    }

    string priceLine;
    getline(cin, priceLine);
    stringstream priceStream(priceLine);
    for (int i = 0; i < 10; ++i) {
        priceStream >> prices[i];
        if (inventory.find(slots[i][0]) != inventory.end()) {
            inventory[slots[i][0]].second = prices[i];
        }
    }

    string product;
    double totalSpent = 0.0;
    while (getline(cin, product)) {
        if (inventory.find(product) == inventory.end() || slots[inventory[product].first].empty()) {
            cout << "Nao temos " << product << " disponivel no momento." << endl;
            continue;
        }

        int slotIndex = inventory[product].first;
        double price = inventory[product].second;

        if (slotIndex == 5) {
            cout << "Opa, um item 0800!" << endl;
        }

        totalSpent += price;
        slots[slotIndex].pop_back();
    }

    cout << fixed << setprecision(2);
    cout << "Compras realizadas com sucesso. Voce gastou R$" << totalSpent << "." << endl;

    return 0;
}
