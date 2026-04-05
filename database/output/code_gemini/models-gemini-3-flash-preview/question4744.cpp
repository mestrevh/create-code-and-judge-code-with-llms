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

    long long q350, q600, q2l;
    if (!(cin >> q350 >> q600 >> q2l)) return 0;

    double total = (q350 * 0.35) + (q600 * 0.60) + (q2l * 2.0);

    cout << "Foram comprados " << fixed << setprecision(1) << total << " litros de refrigerante." << endl;

    return 0;
}