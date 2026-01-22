/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c) {
        cout << "equilatero" << endl;
    } else if (a == b || b == c || a == c) {
        cout << "isosceles" << endl;
    } else {
        cout << "escaleno" << endl;
    }
    
    return 0;
}
