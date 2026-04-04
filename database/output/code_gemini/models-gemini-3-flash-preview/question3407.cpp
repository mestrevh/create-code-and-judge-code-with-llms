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

    int op;
    if (!(cin >> op)) return 0;

    cout << fixed << setprecision(2);

    if (op == 1) {
        double a, b;
        if (cin >> a >> b) {
            cout << a + b << "\n";
        }
    } else if (op == 2) {
        double n;
        if (cin >> n) {
            cout << sqrt(n) << "\n";
        }
    }

    return 0;
}