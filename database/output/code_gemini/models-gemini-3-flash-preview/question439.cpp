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
    if (!(cin >> n)) return 0;

    double total_sales = n * 19.90;
    int num_bonuses = n / 15;
    double bonus_value = num_bonuses * 0.08 * total_sales;
    double total_received = (total_sales * 0.50) + bonus_value;

    cout << fixed << setprecision(2);
    cout << total_sales << "\n";
    cout << bonus_value << "\n";
    cout << total_received << "\n";

    return 0;
}