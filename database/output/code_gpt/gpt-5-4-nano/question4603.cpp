/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];

    long long shifts = 0;
    long long comparisons = 0;

    if (n >= 2) {
        for (long long i = 1; i < n; i++) {
            long long key = a[i];
            long long j = i - 1;
            while (j >= 0) {
                comparisons++;
                if (a[j] <= key) break;
                a[j + 1] = a[j];
                shifts++;
                j--;
            }
            a[j + 1] = key;
        }
    }

    cout << shifts << " " << comparisons << " " << 2;
    return 0;
}