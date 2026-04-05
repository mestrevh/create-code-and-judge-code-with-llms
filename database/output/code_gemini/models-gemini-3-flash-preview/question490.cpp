/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double tree_price;
    if (!(cin >> tree_price)) return 0;

    double total_cost = tree_price;

    for (int i = 0; i < 3; ++i) {
        int quantity;
        double unit_price;
        if (cin >> quantity >> unit_price) {
            total_cost += (quantity * unit_price);
        }
    }

    double per_person = total_cost / 21.0;

    cout << fixed << setprecision(2);
    cout << total_cost << "\n";
    cout << per_person << "\n";

    return 0;
}

// Robson + 20 employees = 21 people total.
// Input format: tree value, then 3 pairs of (qty, price).
// Output format: total cost and cost per person formatted to 2 decimal places.