/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double c1, c2;

    cout << "Digite o valor do primeiro cateto:" << endl;
    if (!(cin >> c1)) return 0;

    cout << "Digite o valor do segundo cateto:" << endl;
    if (!(cin >> c2)) return 0;

    if (c1 <= 0 || c2 <= 0) {
        cout << "Valor de cateto invalido." << endl;
    } else {
        double h = sqrt(c1 * c1 + c2 * c2);
        cout << "O triangulo cujos catetos sao " << c1 << " e " << c2 << " tem hipotenusa " << h << "." << endl;
    }

    return 0;
}