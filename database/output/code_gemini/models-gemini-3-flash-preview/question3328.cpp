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

    int u;
    if (!(cin >> u)) return 0;

    double rate;
    if (u < 100) {
        rate = 1.35;
    } else if (u <= 299) {
        rate = 1.55;
    } else if (u <= 574) {
        rate = 1.75;
    } else {
        rate = 2.15;
    }

    double bill = (double)u * rate;

    if (u > 300) {
        bill *= 1.10;
    }

    if (bill < 35.00) {
        bill = 35.00;
    }

    cout << fixed << setprecision(2) << bill << "\n";
    cout << fixed << setprecision(2) << rate << "\n";

    return 0;
}