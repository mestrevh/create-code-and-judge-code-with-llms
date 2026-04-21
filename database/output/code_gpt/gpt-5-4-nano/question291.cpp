/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long R;
    if (!(cin >> R)) return 0;

    const double pi = 3.14159;
    double volume = (4.0 / 3.0) * pi * (double)R * (double)R * (double)R;

    cout << fixed << setprecision(3);
    cout << "VOLUME = " << volume << "\n";
    return 0;
}