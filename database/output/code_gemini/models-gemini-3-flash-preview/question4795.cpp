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

    double a, b;
    if (!(cin >> a >> b)) return 0;

    double m1 = (a + b) / 2.0;
    double m2 = (m1 + a) / 2.0;
    double m3 = (m2 + a) / 2.0;

    cout << fixed << setprecision(2) << m3 << endl;

    return 0;
}