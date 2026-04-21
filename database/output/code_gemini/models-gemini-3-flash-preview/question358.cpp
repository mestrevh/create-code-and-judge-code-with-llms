/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double F, t;
    int n;

    if (!(cin >> F >> n >> t)) return 0;

    if (t == 0) {
        if (n > 0) {
            cout << (long long)(F / n) << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    double power_term = pow(1.0 + t, n);
    double ant = (power_term - 1.0) / (t * power_term);
    double P = F / ant;

    cout << (long long)P << endl;

    return 0;
}