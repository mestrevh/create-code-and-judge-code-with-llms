/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;

    cout << fixed << setprecision(15);

    cout << a << " + " << b << " = " << a + b << endl;
    cout << b << " - " << a << " = " << b - a << endl;
    cout << a << " * " << b << " = " << a * b << endl;

    if (a == 0) {
        cout << b << " / " << a << " = Indeterminado" << endl;
    } else {
        cout << b << " / " << a << " = " << b / a << endl;
    }

    return 0;
}
