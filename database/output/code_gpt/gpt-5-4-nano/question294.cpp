/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X;
    double Y;
    if (!(cin >> X)) return 0;
    if (!(cin >> Y)) return 0;

    double consumo = X / Y;

    cout << fixed << setprecision(3) << consumo << " km/l";
    return 0;
}