/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "Se a = 0, nao temos uma equacao do segundo grau." << endl;
    } else {
        double delta = b * b - 4 * a * c;
        cout << fixed << setprecision(2);
        cout << "Para os seguintes coeficientes: " << a << ", " << b << " e " << c << ". O delta eh: " << delta << endl;

        if (delta > 0) {
            double raiz1 = (-b + sqrt(delta)) / (2 * a);
            double raiz2 = (-b - sqrt(delta)) / (2 * a);
            cout << "A equacao possui duas raizes reais distintas." << endl;
            cout << "As raizes sao: " << raiz1 << " e " << raiz2 << endl;
        } else if (delta == 0) {
            double raiz = -b / (2 * a);
            cout << "A equacao possui duas raizes reais iguais." << endl;
            cout << "As raizes sao: " << raiz << " e " << raiz << endl;
        } else {
            cout << "A equacao nao possui raizes reais." << endl;
        }
    }
    return 0;
}
