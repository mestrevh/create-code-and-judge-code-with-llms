/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b;
    while (cin >> a >> b) {
        cout << "Digite um numero:\n";
        cout << "Digite outro numero:\n";
        double maior = (a > b) ? a : b;
        cout << "Maior numero: " << fixed << setprecision(1) << maior << "\n";
    }

    return 0;
}