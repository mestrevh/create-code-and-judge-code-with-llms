/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double r, h;
    if (cin >> r >> h) {
        const double pi = acos(-1.0);
        double volume = pi * r * r * h;
        cout << fixed << setprecision(2) << volume << endl;
    }

    return 0;
}