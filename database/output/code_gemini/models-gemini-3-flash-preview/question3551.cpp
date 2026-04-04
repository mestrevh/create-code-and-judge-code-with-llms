/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            cout << "eh equilatero" << endl;
        } else if (a == b || a == c || b == c) {
            cout << "eh isosceles" << endl;
        } else {
            cout << "eh escaleno" << endl;
        }
    } else {
        cout << "nao eh triangulo" << endl;
    }

    return 0;
}