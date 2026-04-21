/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> slots[10];
    string line;
    for (int i = 0; i < 10; ++i) {
        if (getline(cin, line)) {
            stringstream ss(line);
            string item;
            while (ss >> item) {
                slots[i].push_back(item);
            }
        }
    }

    double prices[10];
    for (int i = 0; i < 10; ++i) {
        if (!(cin >> prices[i])) break;
    }
    
    // Slot 35 is historically the 6th slot (indices 30-39).
    // The problem states slot 35 is currently free.
    prices[5] = 0.0;

    // Consume the remainder of the line containing the prices.
    getline(cin, line);

    double total_spent = 0.0;
    string query;
    while (getline(cin, query)) {
        // Trim leading and trailing whitespace and potential \r characters.
        size_t first = query.find_first_not_of(" \t\r\n");
        if (first == string::npos) continue;
        size_t last = query.find_last_not_of(" \t\r\n");
        query = query.substr(first, (last - first + 1));

        bool found = false;
        // Search through the slots from top to bottom (slot 30 to 39).
        for (int i = 0; i < 10; ++i) {
            // A product is available only if it is at the front (the last one inserted).
            if (!slots[i].empty() && slots[i].back() == query) {
                if (i == 5) {
                    cout << "Opa, um item 0800!" << endl;
                }
                total_spent += prices[i];
                slots[i].pop_back();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Nao temos " << query << " disponivel no momento." << endl;
        }
    }

    cout << "Compras realizadas com sucesso. Voce gastou R$" << fixed << setprecision(2) << total_spent << "." << endl;

    return 0;
}