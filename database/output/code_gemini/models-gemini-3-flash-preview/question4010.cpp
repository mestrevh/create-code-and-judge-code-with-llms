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
    cout << "Digite a quantidade de macas:" << endl;
    
    if (!(cin >> n)) return 0;

    double price_per_unit = (n < 12) ? 0.30 : 0.25;
    double total = n * price_per_unit;

    cout << fixed << setprecision(2);
    cout << "Valor total: R$ " << total << endl;

    return 0;
}