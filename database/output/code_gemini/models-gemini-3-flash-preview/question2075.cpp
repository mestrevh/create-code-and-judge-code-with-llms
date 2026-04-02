/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    double total_sum = 0.0;
    for (long long i = 0; i <= m; ++i) {
        long long count = min(i, n) + 1;
        if (count > 0) {
            total_sum += (sin((double)i) + cos((double)i)) * (double)count;
        }
    }

    cout << fixed << setprecision(6) << total_sum << endl;

    return 0;
}