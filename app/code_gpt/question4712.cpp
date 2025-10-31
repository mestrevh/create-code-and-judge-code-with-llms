/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

void calculadora(double A, double B) {
    cout << fixed << setprecision(1);
    cout << A << " + " << B << " = " << A + B << endl;
    cout << B << " - " << A << " = " << B - A << endl;
    cout << A << " * " << B << " = " << A * B << endl;
    if (A == 0) {
        cout << B << " / " << A << " = Indeterminado" << endl;
    } else {
        cout << B << " / " << A << " = " << B / A << endl;
    }
}

int main() {
    double A, B;
    cin >> A >> B;
    calculadora(A, B);
    return 0;
}
