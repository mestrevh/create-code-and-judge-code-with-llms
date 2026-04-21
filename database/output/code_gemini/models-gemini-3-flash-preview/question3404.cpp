/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    double delta = b * b - 4.0 * a * c;
    double sqrt_delta = sqrt(delta);

    double x1 = (-b - sqrt_delta) / (2.0 * a);
    double x2 = (-b + sqrt_delta) / (2.0 * a);

    if (x1 > x2) swap(x1, x2);

    cout << fixed << setprecision(2) << x1 << " " << x2 << endl;

    return 0;
}

