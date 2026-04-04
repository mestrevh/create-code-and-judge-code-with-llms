/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b, c;
    while (cin >> a >> b >> c) {
        cout << "Digite um numero:" << "\n";
        cout << "Digite outro numero:" << "\n";
        cout << "Digite outro numero:" << "\n";

        double m = a;
        if (b > m) {
            m = b;
        }
        if (c > m) {
            m = c;
        }

        cout << "Maior numero: " << fixed << setprecision(1) << m << "\n";
    }

    return 0;
}