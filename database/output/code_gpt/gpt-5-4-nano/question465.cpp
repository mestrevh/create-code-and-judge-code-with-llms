/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double x;
    long double sum = 0.0L;
    long long cnt = 0;

    while (cin >> x) {
        if (x < 0) break;
        sum += x;
        cnt++;
    }

    long double avg = (cnt == 0) ? 0.0L : sum / cnt;

    cout << fixed << setprecision(2) << (double)sum << "\n";
    cout << fixed << setprecision(2) << (double)avg << "\n";
    return 0;
}