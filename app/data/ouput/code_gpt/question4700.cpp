/*
Código criado pelo GPT 4o-mini
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
        if (maior == static_cast<int>(maior)) {
            cout << static_cast<int>(maior) << endl;
        } else {
            cout << fixed << setprecision(1) << maior << endl;
        }
    }
}

int main() {
    double num1, num2;
    cin >> num1 >> num2;
    maior_numero(num1, num2);
    return 0;
}
