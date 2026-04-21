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

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        double a, b;
        char op;
        if (!(cin >> a >> op >> b)) break;

        double result = 0.0;
        if (op == '#') {
            result = pow(a, b) * pow(b, a);
        } else if (op == '@') {
            result = pow(a, b) / pow(b, a);
        } else if (op == '&') {
            result = (b * sqrt(a)) + (a * sqrt(b));
        } else if (op == '%') {
            result = (b * sqrt(a)) - (a * sqrt(b));
        }

        cout << fixed << setprecision(2) << result << "\n";
    }

    return 0;
}