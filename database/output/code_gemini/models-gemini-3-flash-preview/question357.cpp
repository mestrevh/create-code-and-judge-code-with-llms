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

    double n;
    if (!(cin >> n)) return 0;

    int prestacao = (int)(n / 3.0);
    double entrada = n - (2.0 * prestacao);

    cout << fixed << setprecision(2) << entrada << "\n";
    cout << fixed << setprecision(2) << (double)prestacao << "\n";
    cout << fixed << setprecision(2) << (double)prestacao << "\n";

    return 0;
}

