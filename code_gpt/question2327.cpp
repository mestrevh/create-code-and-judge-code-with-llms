/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

double menor(double x, double y, double z) {
    return min(x, min(y, z));
}

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double resultado = menor(a, b, c);
    cout << fixed << setprecision(2) << resultado << endl;
    return 0;
}
