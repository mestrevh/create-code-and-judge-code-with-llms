/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

double obterMaior(double v, double w, double x, double y, double z) {
    return max({v, w, x, y, z});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double v, w, x, y, z;
    if (cin >> v >> w >> x >> y >> z) {
        cout << fixed << setprecision(2) << obterMaior(v, w, x, y, z) << "\n";
    }

    return 0;
}