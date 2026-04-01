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

    int days;
    double km;

    if (!(cin >> days >> km)) return 0;

    double daily_cost = days * 30.00;
    double km_cost = km * 0.01;
    double subtotal = daily_cost + km_cost;
    double total = subtotal * 0.90;

    cout << fixed << setprecision(2) << total << endl;

    return 0;
}