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

    double result = 0.0;
    for (long long i = 1; i <= n; ++i) {
        if (i % 2 != 0) {
            result -= 1.0 / (double)i;
        } else {
            result += 1.0 / (double)i;
        }
    }

    cout << fixed << setprecision(6) << result << endl;

    return 0;
}