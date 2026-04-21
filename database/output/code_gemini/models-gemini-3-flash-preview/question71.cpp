/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Item {
    int code;
    int quantity;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Item> stock;
    map<int, int> codeToIndex;
    int n, m;
    int index = 0;

    // Read initial stock
    while (cin >> n && n != 9999) {
        if (!(cin >> m)) break;
        // In case of duplicate codes in input, we update lookup to point to the latest
        // though the problem implies a unique list of up to 100 items.
        codeToIndex[n] = index++;
        stock.push_back({n, m});
    }

    int i, j, k;
    // Read orders: i = customer, j = product code, k = requested quantity
    while (cin >> i && i != 9999) {
        if (!(cin >> j >> k)) break;
        auto it = codeToIndex.find(j);
        if (it != codeToIndex.end()) {
            int stockIdx = it->second;
            if (stock[stockIdx].quantity >= k) {
                stock[stockIdx].quantity -= k;
                cout << "OK\n";
            } else {
                cout << "ESTOQUE INSUFICIENTE\n";
            }
        } else {
            // Product code not found in inventory
            cout << "ESTOQUE INSUFICIENTE\n";
        }
    }

    // Print final stock status in the original order of insertion
    for (const auto& item : stock) {
        cout << item.code << " " << item.quantity << "\n";
    }

    return 0;
}
