/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

double maiorNumero(double a, double b, double c, double d) {
    return max(max(a, b), max(c, d));
}

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << fixed << setprecision(2) << maiorNumero(a, b, c, d) << endl;
    return 0;
}
