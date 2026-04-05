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

    vector<long long> small, large;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            small.push_back(i);
            long long j = n / i;
            if (j != i) large.push_back(j);
        }
    }

    sort(small.begin(), small.end());
    sort(large.begin(), large.end());

    bool first = true;
    auto printVal = [&](long long x) {
        if (x > n) return;
        if (!first) cout << "\n";
        cout << x;
        first = false;
    };

    for (long long x : small) printVal(x);

    reverse(large.begin(), large.end());
    for (long long x : large) printVal(x);

    if (!small.empty() && small.back() == n) {
    }

    return 0;
}