/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

double menor(double X, double Y, double Z) {
    return min({X, Y, Z});
}

int main() {
    double X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return 0;
    cout << fixed << setprecision(2) << menor(X, Y, Z) << "\n";
    return 0;
}