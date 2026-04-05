/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c;
    if (!(cin >> a)) return 0;
    if (!(cin >> b)) return 0;
    if (!(cin >> c)) return 0;

    double avg = (a + b + c) / 3.0;
    cout << fixed << setprecision(6) << avg;
    return 0;
}