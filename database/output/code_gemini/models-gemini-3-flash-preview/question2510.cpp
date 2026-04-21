/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

struct Gift {
    string name;
    double price;
    int preference;

    bool operator<(const Gift& other) const {
        if (preference != other.preference) {
            return preference > other.preference;
        }
        if (price != other.price) {
            return price < other.price;
        }
        return name < other.name;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string owner;
    while (cin >> owner && owner != "*") {
        int q;
        if (!(cin >> q)) break;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<Gift> gifts(q);
        for (int i = 0; i < q; ++i) {
            getline(cin, gifts[i].name);
            cin >> gifts[i].price >> gifts[i].preference;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        sort(gifts.begin(), gifts.end());

        cout << "Lista de " << owner << "\n";
        cout << fixed << setprecision(2);
        for (int i = 0; i < q; ++i) {
            cout << gifts[i].name << " - R$" << gifts[i].price << "\n";
        }
        cout << "\n";
    }

    return 0;
}

