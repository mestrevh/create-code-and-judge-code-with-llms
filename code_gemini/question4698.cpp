/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

double somar(double a, double b) {
    return a + b;
}

int main() {
    double a, b;
    cin >> a >> b;

    double c = somar(a, b);

    if (static_cast<int>(c) == c) {
        cout << "O resultado de " << fixed << setprecision(1) << a << " + " << fixed << setprecision(1) << b << " eh " << static_cast<int>(c) << endl;
    } else {
        cout << "O resultado de " << fixed << setprecision(1) << a << " + " << fixed << setprecision(1) << b << " eh " << fixed << setprecision(1) << c << endl;
    }

    return 0;
}
