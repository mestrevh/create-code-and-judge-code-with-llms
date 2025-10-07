/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "nao eh triangulo" << endl;
    } else if (a == b && b == c) {
        cout << "eh equilatero" << endl;
    } else if (a == b || b == c || a == c) {
        cout << "eh isosceles" << endl;
    } else {
        cout << "eh escaleno" << endl;
    }

    return 0;
}
