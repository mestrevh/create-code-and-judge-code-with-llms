/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Product {
    string name;
    double price;
    int qty;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Product> prods(n);
    for (int i = 0; i < n; i++) {
        cin >> prods[i].name >> prods[i].price >> prods[i].qty;
    }

    sort(prods.begin(), prods.end(), [](const Product& a, const Product& b) {
        return a.name < b.name;
    });

    string s, date, paidStr;
    while (cin >> s) {
        if (s == "dia") {
            cin >> date;
        } else {
            size_t pos = s.find("R$");
            if (pos != string::npos) {
                if (s.length() > pos + 2) {
                    paidStr = s.substr(pos + 2);
                } else {
                    cin >> paidStr;
                }
                break;
            }
        }
    }

    string paidValStr = paidStr;
    for (char &c : paidValStr) {
        if (c == ',') c = '.';
    }
    double paidVal = atof(paidValStr.c_str());

    cout << "=============\n";
    cout << "NF - 0123\n";
    cout << "Data - " << date << "\n";
    cout << "=============\n";

    double total = 0;
    for (const auto& p : prods) {
        double itemTotal = p.price * (double)p.qty;
        cout << p.qty << "x " << p.name << " - R$" << fixed << setprecision(2) << itemTotal << "\n";
        total += itemTotal;
    }

    cout << "\n";
    cout << "Valor Total - R$" << fixed << setprecision(2) << total << "\n";
    cout << "Pago - R$" << paidStr << "\n";
    cout << "Troco - R$" << fixed << setprecision(2) << (paidVal - total) << "\n";
    cout << "=============";

    return 0;
}