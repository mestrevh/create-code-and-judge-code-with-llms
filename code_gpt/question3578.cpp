/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;

    cout << fixed << setprecision(2);
    cout << (a + b) << endl;
    cout << (a - b) << endl;
    cout << (a * b) << endl;
    if (b != 0) {
        cout << (a / b) << endl;
    } else {
        cout << "Divisão por zero" << endl; // Tratamento básico
    }

    return 0;
}
