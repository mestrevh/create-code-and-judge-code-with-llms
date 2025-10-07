/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    cout << "Informe o comprimento do primeiro lado do triangulo:\n";
    cin >> a;
    cout << "Informe o comprimento do segundo lado do triangulo:\n";
    cin >> b;
    cout << "Informe o comprimento do terceiro lado do triangulo:\n";
    cin >> c;

    if (a + b > c && a + c > b && b + c > a) {
        cout << "Os lados informados podem formar um triangulo\n";
        if (a == b && b == c) {
            cout << "Triangulo Equilatero\n";
        } else if (a == b || a == c || b == c) {
            cout << "Triangulo Isosceles\n";
        } else {
            cout << "Triangulo Escaleno\n";
        }
    } else {
        cout << "Os lados informados nao podem formar um triangulo\n";
    }

    return 0;
}
