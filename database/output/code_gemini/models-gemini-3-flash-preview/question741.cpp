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

    long long N;
    if (!(cin >> N)) return 0;

    if (N >= 0) {
        double S = 0.0;
        for (long long i = 0; i <= N; ++i) {
            S += (double)i / (i + 1.0);
        }
        cout << setprecision(16) << S << endl;
    } else {
        long long N_pos = -N;
        double P = 1.0;
        for (long long i = 1; i <= N_pos; ++i) {
            P *= (double)(i + 2.0) / i;
        }
        cout << setprecision(16) << P << endl;
    }

    return 0;
}