/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

double maior(double v, double w, double x, double y, double z) {
    return max(max(v, w), max(max(x, y), z));
}

int main() {
    double a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << fixed << setprecision(2) << maior(a, b, c, d, e) << endl;
    return 0;
}
