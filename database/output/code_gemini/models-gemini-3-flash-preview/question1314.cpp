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
    if (!(cin >> a >> b >> c)) return 0;

    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        if (a == b && b == c) {
            cout << "Equilatero" << endl;
        } else if (a == b || b == c || a == c) {
            cout << "Isosceles" << endl;
        } else {
            cout << "Escaleno" << endl;
        }
    } else {
        cout << "Nao eh triangulo" << endl;
    }

    return 0;
}