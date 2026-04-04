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

    cout << "Digite o comprimento do lado A:\n";
    if (!(cin >> a)) return 0;
    cout << "Digite o comprimento do lado B:\n";
    if (!(cin >> b)) return 0;
    cout << "Digite o comprimento do lado C:\n";
    if (!(cin >> c)) return 0;

    if (a == b && b == c) {
        cout << "Este e um triangulo equilatero.\n";
    } else if (a == b || b == c || a == c) {
        cout << "Este e um triangulo isosceles.\n";
    } else {
        cout << "Este e um triangulo escaleno.\n";
    }

    return 0;
}