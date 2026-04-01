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

    double b_menor, b_maior, altura;
    if (cin >> b_menor >> b_maior >> altura) {
        double area = ((b_menor + b_maior) * altura) / 2.0;
        cout << fixed << setprecision(1) << area << endl;
    }

    return 0;
}