/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << fixed << setprecision(2) << a * b + c / d << endl;
    cout << fixed << setprecision(2) << (((a * b) + c) / d) << endl;

    return 0;
}
