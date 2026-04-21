/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b, c;
    while (true) {
        cout << "Informe o comprimento do primeiro lado do triangulo:\n";
        if (!(cin >> a)) break;
        cout << "Informe o comprimento do segundo lado do triangulo:\n";
        if (!(cin >> b)) break;
        cout << "Informe o comprimento do terceiro lado do triangulo:\n";
        if (!(cin >> c)) break;

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
    }

    return 0;
}