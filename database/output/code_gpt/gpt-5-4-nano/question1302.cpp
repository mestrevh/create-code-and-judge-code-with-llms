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
    long double sumPos = 0;
    long long cntPos = 0;

    long long mn = LLONG_MAX;
    long long sumOffDiag = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!(cin >> x)) return 0;
            mn = min(mn, x);
            if (x > 0) {
                sumPos += x;
                cntPos++;
            }
            if (i != j) sumOffDiag += x;
        }
    }

    long double avg = (cntPos == 0) ? 0.0L : sumPos / (long double)cntPos;
    int delta = (mn % 2 == 0) ? 1 : 0;

    cout << fixed << setprecision(2) << (double)avg << " " << mn << " " << delta << " " << sumOffDiag;
    return 0;
}