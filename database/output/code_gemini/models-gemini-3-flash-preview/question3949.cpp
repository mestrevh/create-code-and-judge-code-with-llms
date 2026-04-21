/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>

using namespace std;

struct Item {
    string name;
    double price;
};

struct Market {
    int id;
    int distance;
    map<string, double> inventory;
};

struct ShoppingList {
    int numItems;
    vector<string> desiredItems;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Market> markets(n);
    for (int i = 0; i < n; ++i) {
        markets[i].id = i + 1;
        int m;
        if (!(cin >> markets[i].distance >> m)) break;
        for (int j = 0; j < m; ++j) {
            string name, dash;
            double price;
            cin >> name >> dash >> price;
            markets[i].inventory[name] = price;
        }
    }

    ShoppingList list;
    if (!(cin >> list.numItems)) return 0;
    list.desiredItems.resize(list.numItems);
    for (int i = 0; i < list.numItems; ++i) {
        cin >> list.desiredItems[i];
    }

    int bestIdx = -1;
    int maxMatches = -1;
    int minDist = 2147483647;

    for (int i = 0; i < n; ++i) {
        int matches = 0;
        for (const string& s : list.desiredItems) {
            if (markets[i].inventory.find(s) != markets[i].inventory.end()) {
                matches++;
            }
        }
        
        if (matches > maxMatches) {
            maxMatches = matches;
            minDist = markets[i].distance;
            bestIdx = i;
        } else if (matches == maxMatches && bestIdx != -1) {
            if (markets[i].distance < minDist) {
                minDist = markets[i].distance;
                bestIdx = i;
            }
        }
    }

    if (bestIdx != -1) {
        cout << "Mercado: " << markets[bestIdx].id << "\n";
        double total = 0;
        for (const string& s : list.desiredItems) {
            auto it = markets[bestIdx].inventory.find(s);
            if (it != markets[bestIdx].inventory.end()) {
                cout << s << " " << fixed << setprecision(2) << it->second << "\n";
                total += it->second;
            }
        }
        cout << fixed << setprecision(2) << total << endl;
    }

    return 0;
}