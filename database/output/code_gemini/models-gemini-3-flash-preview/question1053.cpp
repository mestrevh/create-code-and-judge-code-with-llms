/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double h, r;
    if (!(cin >> h >> r)) return 0;

    const double pi = 3.14;

    double volume = pi * r * r * h;
    double area = 2.0 * pi * r * r + 2.0 * pi * r * h;

    cout << fixed << setprecision(2) << volume << "\n" << area << endl;

    return 0;
}