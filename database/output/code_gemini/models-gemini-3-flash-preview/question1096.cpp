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

    int n;
    if (!(cin >> n)) return 0;

    double s = 0.0;
    double current_term = 2.0;
    const double pi = 3.14;

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            current_term = 2.0;
        } else if (i % 2 == 0) {
            current_term *= 4.0;
        } else {
            current_term += pi;
        }
        s += current_term;
    }

    cout << "Valor de S : " << fixed << setprecision(2) << s << endl;

    return 0;
}