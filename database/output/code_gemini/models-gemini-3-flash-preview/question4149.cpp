/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    if (n < 3) {
        cout << "Valor invalido" << endl;
    } else {
        vector<double> f(n + 2);
        f[1] = 0;
        f[2] = 1;
        for (int i = 3; i <= n + 1; ++i) {
            f[i] = f[i - 1] + f[i - 2];
        }

        double ratio;
        if (n == 3) {
            ratio = f[3] / f[2];
        } else {
            ratio = f[n + 1] / f[n];
        }

        cout << fixed << setprecision(15) << ratio << endl;
    }

    return 0;
}

