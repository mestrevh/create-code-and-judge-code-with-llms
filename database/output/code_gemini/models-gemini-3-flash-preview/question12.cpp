/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    map<int, double> menu;
    for (int i = 0; i < n; ++i) {
        int code;
        string desc;
        double price;
        if (!(cin >> code)) break;
        // Skip whitespace/newline after the code and read the full product description
        getline(cin >> ws, desc);
        if (!(cin >> price)) break;
        menu[code] = price;
    }

    double total = 0.0;
    int order_code;
    // Read product codes for the order. The value 0 terminates the order section.
    while (cin >> order_code && order_code != 0) {
        int qty;
        if (!(cin >> qty)) break;
        // Process only registered codes and valid (positive) quantities
        if (qty > 0 && menu.count(order_code)) {
            total += menu[order_code] * (double)qty;
        }
    }

    // Output the final bill formatted to two decimal places
    cout << fixed << setprecision(2) << total << endl;

    return 0;
}