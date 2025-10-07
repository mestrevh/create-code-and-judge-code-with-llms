/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

double dobroDoMaior(double a, double b) {
    return 2 * max(a, b);
}

int main() {
    double num1, num2;
    cin >> num1 >> num2;
    cout << fixed << setprecision(2) << dobroDoMaior(num1, num2) << endl;
    return 0;
}
