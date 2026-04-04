/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    if (!(cin >> n >> k)) return 0;

    if (k < 0 || k > n) {
        cout << 0 << "\n";
        return 0;
    }

    if (k == 0 || k == n) {
        cout << 1 << "\n";
        return 0;
    }

    if (k > n / 2) {
        k = n - k;
    }

    unsigned long long result = 1;
    for (long long i = 1; i <= k; ++i) {
        result = result * (n - i + 1) / i;
    }

    cout << result << "\n";

    return 0;
}
