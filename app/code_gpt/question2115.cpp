/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double x;
    cin >> x;
    int sinal = (x > 0) - (x < 0);
    cout << fixed << setprecision(4) << "sinal(" << x << "e" << (x != 0 ? (x < 0 ? "" : "+") : "") << (x == 0 ? 0 : (int)log10(fabs(x))) << ") = " << (sinal == 0 ? 0 : (sinal == 1 ? "+1" : "-1")) << endl;
    return 0;
}
