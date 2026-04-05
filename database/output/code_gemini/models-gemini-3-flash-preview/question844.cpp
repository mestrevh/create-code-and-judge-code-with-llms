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

    int code;
    double qty, unit_price;
    bool found = false;

    int best_code;
    double best_qty;
    double max_total_cost;

    while (cin >> code && code != 0) {
        if (!(cin >> qty >> unit_price)) break;
        
        double current_total_cost = qty * unit_price;
        
        if (!found || current_total_cost > max_total_cost) {
            max_total_cost = current_total_cost;
            best_code = code;
            best_qty = qty;
            found = true;
        }
    }

    if (!found) {
        cout << "nao tem compras" << endl;
    } else {
        cout << "Item mais caro" << endl;
        cout << "Codigo: " << best_code << endl;
        cout << "Quantidade: " << best_qty << endl;
        cout << "Custo: " << fixed << setprecision(2) << max_total_cost << endl;
    }

    return 0;
}