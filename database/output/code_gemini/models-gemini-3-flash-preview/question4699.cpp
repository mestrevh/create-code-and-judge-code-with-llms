/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

void maior_numero(double a, double b) {
    if (a == b) {
        cout << "São iguais" << endl;
    } else {
        double maior = (a > b) ? a : b;
        cout << fixed << setprecision(1) << maior << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double num1, num2;
    if (cin >> num1 >> num2) {
        maior_numero(num1, num2);
    }

    return 0;
}