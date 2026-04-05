/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double A, B, C;
    if (!(cin >> A >> B >> C)) return 0;

    double media = (A * 2.0 + B * 3.0 + C * 5.0) / 10.0;

    cout << "MEDIA = " << fixed << setprecision(1) << media << "\n";
    return 0;
}