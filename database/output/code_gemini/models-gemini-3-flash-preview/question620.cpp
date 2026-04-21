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

    double x, y, t;
    const double PI = acos(-1.0);

    while (cin >> x >> y >> t) {
        double rad = t * PI / 180.0;
        double cos_t = cos(rad);
        double sin_t = sin(rad);

        double nx = x * cos_t - y * sin_t;
        double ny = x * sin_t + y * cos_t;

        cout << fixed << setprecision(2) << nx << " " << ny << "\n";
    }

    return 0;
}