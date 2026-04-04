/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char type;
    double val;

    if (!(cin >> type)) return 0;
    if (!(cin >> val)) {
        cout << "Entrada invalida!" << endl;
        return 0;
    }

    if (val <= 0) {
        cout << "Entrada invalida!" << endl;
        return 0;
    }

    if (type == 'C' || type == 'c') {
        double area = 3.141 * val * val;
        cout << fixed << setprecision(2) << area << "\nCirculo" << endl;
    } else if (type == 'Q' || type == 'q') {
        double area = val * val;
        cout << fixed << setprecision(2) << area << "\nQuadrado" << endl;
    } else if (type == 'T' || type == 't') {
        double area = (val * val * 1.7) / 4.0;
        cout << fixed << setprecision(2) << area << "\nTriangulo" << endl;
    } else {
        cout << "Entrada invalida!" << endl;
    }

    return 0;
}