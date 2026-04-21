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

    double valor;
    int anos;

    if (!(cin >> valor >> anos)) return 0;

    double taxa = 0.0;
    if (anos == 1) {
        taxa = 0.03;
    } else if (anos == 2) {
        taxa = 0.05;
    }

    double total = valor * (1.0 + taxa);

    cout << fixed << setprecision(2) << total << endl;

    return 0;
}