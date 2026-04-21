/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    long long cnt = 0;
    long double sum = 0;

    while (cin >> x) {
        if (x < 0) break;
        sum += x;
        cnt++;
    }

    if (cnt == 0) {
        cout << fixed << setprecision(2) << 0.00 << "\n";
        return 0;
    }

    long double avg = sum / cnt;
    cout << fixed << setprecision(2) << (double)avg << "\n";
    return 0;
}