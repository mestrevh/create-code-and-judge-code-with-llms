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

    long long n;
    if (!(cin >> n)) return 0;

    if (n <= 0) {
        cout << fixed << setprecision(2) << 0.00 << endl;
    } else {
        for (long long i = 1; i <= n; ++i) {
            cout << i << "/" << 3 * i;
            if (i < n) {
                cout << " + ";
            }
        }
        cout << fixed << setprecision(2) << "\n" << (double)n / 3.0 << endl;
    }

    return 0;
}