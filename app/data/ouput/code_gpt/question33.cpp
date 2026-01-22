/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int a, b, c, d;
    char op, slash1, slash2;

    cin >> a >> slash1 >> b >> op >> c >> slash2 >> d;

    if (b == 0 || d == 0) {
        cout << "entrada invalida!" << endl;
        return 0;
    }

    int numerator = a * d + b * c;
    int denominator = b * d;

    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    cout << numerator << "/" << denominator << endl;
    return 0;
}
