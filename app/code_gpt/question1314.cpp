/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            cout << "Equilatero" << endl;
        } else if (a == b || a == c || b == c) {
            cout << "Isosceles" << endl;
        } else {
            cout << "Escaleno" << endl;
        }
    } else {
        cout << "Nao eh triangulo" << endl;
    }

    return 0;
}
