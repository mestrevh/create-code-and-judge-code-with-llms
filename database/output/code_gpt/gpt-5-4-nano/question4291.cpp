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

    long double sum = 0.0;
    for (int i = 0; i < n; i++) {
        long double x;
        cin >> x;
        sum += x;
    }

    long double avg = sum / n;
    cout << fixed << setprecision(15) << (double)avg;
    return 0;
}