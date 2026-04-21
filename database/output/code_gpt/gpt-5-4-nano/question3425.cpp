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

    vector<long double> a(n);
    long double mn = numeric_limits<long double>::infinity();
    long double mx = -numeric_limits<long double>::infinity();
    long double sum = 0;

    long long evenCount = 0;
    for (int i = 0; i < n; i++) {
        long double x;
        cin >> x;
        a[i] = x;
        mn = min(mn, x);
        mx = max(mx, x);
        sum += x;

        long long xi = llround((double)x);
        if ((long double)xi == x && xi % 2 == 0) evenCount++;
    }

    long double perc = (n == 0) ? 0.0L : (100.0L * (long double)evenCount / (long double)n);
    long double avg = (n == 0) ? 0.0L : (sum / (long double)n);

    cout.setf(ios::fixed);
    cout << setprecision(1) << (double)mn << "\n";
    cout << setprecision(1) << (double)mx << "\n";
    cout << setprecision(2) << (double)perc << "\n";
    cout << setprecision(2) << (double)avg << "\n";

    return 0;
}