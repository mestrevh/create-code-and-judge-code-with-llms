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

    double x;
    int n;

    if (!(cin >> x >> n)) return 0;

    double result = 0.0;
    double term = 1.0;

    for (int i = 0; i < n; ++i) {
        result += term;
        term *= (x / (i + 1));
    }

    cout << fixed << setprecision(5) << result << endl;

    return 0;
}