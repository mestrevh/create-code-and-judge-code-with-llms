/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            cout << "EQUILATERO" << endl;
        } else if (a == b || a == c || b == c) {
            cout << "ISOSCELES" << endl;
        } else {
            cout << "ESCALENO" << endl;
        }
    } else {
        cout << "-" << endl;
    }
    
    return 0;
}
