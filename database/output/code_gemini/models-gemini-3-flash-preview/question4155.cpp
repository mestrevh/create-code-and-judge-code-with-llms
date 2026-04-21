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

    double a, b;
    if (!(cin >> a >> b)) return 0;

    double sum = a + b;
    double sub = a - b;
    double prod = a * b;
    double div = (b != 0) ? (a / b) : 0.0;

    cout << fixed << setprecision(2);
    cout << sum << ", " << sub << ", " << prod << ", " << div << "\n";

    return 0;
}