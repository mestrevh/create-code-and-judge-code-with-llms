/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string figura;
    while (cin >> figura) {
        if (figura == "retangulo") {
            double base, altura;
            if (cin >> base >> altura) {
                cout << fixed << setprecision(2) << (base * altura) << "\n";
            }
        } else if (figura == "triangulo") {
            double base, altura;
            if (cin >> base >> altura) {
                cout << fixed << setprecision(2) << (base * altura / 2.0) << "\n";
            }
        } else if (figura == "trapezio") {
            double b_maior, b_menor, altura;
            if (cin >> b_maior >> b_menor >> altura) {
                cout << fixed << setprecision(2) << ((b_maior + b_menor) * altura / 2.0) << "\n";
            }
        } else if (figura == "circulo") {
            double raio;
            if (cin >> raio) {
                cout << fixed << setprecision(2) << (3.1415 * raio * raio) << "\n";
            }
        } else {
            cout << "Figura invalida.\n";
        }
    }

    return 0;
}