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

    double a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        double math1 = (a * b) + (c / d);
        double math2 = ((a * b) + c) / d;

        cout << fixed << setprecision(2) << math1 << "\n";
        cout << fixed << setprecision(2) << math2 << "\n";
    }

    return 0;
}