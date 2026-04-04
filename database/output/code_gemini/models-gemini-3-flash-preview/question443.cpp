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

    int n;
    if (cin >> n) {
        double bread_unit_price = 4.15 / 23.0;
        double cheese_unit_price = 3.89 / 8.0;
        
        double total_cost = (double)n * (2.0 * bread_unit_price + cheese_unit_price);
        
        cout << fixed << setprecision(2) << total_cost << endl;
    }

    return 0;
}