/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n < 1) return 0;

    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;

    for (long long p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (long long i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }

    bool first = true;
    for (int i = 1; i <= n; i++) {
        if (!is_prime[i]) {
            if (!first) {
                cout << " ";
            }
            cout << i;
            first = false;
        }
    }
    cout << endl;

    return 0;
}