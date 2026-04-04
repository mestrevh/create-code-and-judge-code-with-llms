/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    double r;

    if (cin >> n >> r) {
        const double PI = acos(-1.0);
        double perimeter = (double)n * 2.0 * r * sin(PI / (double)n);
        cout << fixed << setprecision(2) << perimeter << endl;
    }

    return 0;
}