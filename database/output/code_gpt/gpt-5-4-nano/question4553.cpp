/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    double media = (double)sum / (double)n;

    sort(a.begin(), a.end());
    double mediana;
    if (n % 2 == 1) {
        mediana = (double)a[n/2];
    } else {
        mediana = ((double)a[n/2 - 1] + (double)a[n/2]) / 2.0;
    }

    unordered_map<long long, int> freq;
    freq.reserve(n * 2);
    long long moda = a[0];
    int best = 0;
    for (auto x : a) {
        int f = ++freq[x];
        if (f > best || (f == best && x > moda)) {
            best = f;
            moda = x;
        }
    }

    cout.setf(ios::fixed);
    cout << setprecision(2) << media << ' ' << mediana << ' ' << (double)moda;
    return 0;
}