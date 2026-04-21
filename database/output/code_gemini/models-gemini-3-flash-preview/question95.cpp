/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    string name;
    double price;
};

bool compareByPrice(const Item& a, const Item& b) {
    if (a.price != b.price) {
        return a.price < b.price;
    }
    return a.name < b.name;
}

bool compareByName(const Item& a, const Item& b) {
    return a.name < b.name;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double budget;
    if (!(cin >> budget)) return 0;

    int n;
    if (!(cin >> n)) return 0;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].name >> items[i].price;
    }

    sort(items.begin(), items.end(), compareByPrice);

    vector<Item> purchased;
    double current_money = budget;

    for (int i = 0; i < n; ++i) {
        if (current_money >= items[i].price) {
            current_money -= items[i].price;
            purchased.push_back(items[i]);
        }
    }

    sort(purchased.begin(), purchased.end(), compareByName);

    for (const auto& item : purchased) {
        cout << item.name << " " << fixed << setprecision(2) << item.price << "\n";
    }

    cout << fixed << setprecision(2) << current_money << endl;

    return 0;
}