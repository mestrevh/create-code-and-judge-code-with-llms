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

    double base_maior, base_menor, altura;

    if (cin >> base_maior >> base_menor >> altura) {
        double area = ((base_maior + base_menor) * altura) / 2.0;
        cout << fixed << setprecision(1) << area << endl;
    }

    return 0;
}