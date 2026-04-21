/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a(10);
    for (int i = 0; i < 10; i++) cin >> a[i];

    long long sum = 0;
    long long sumDiv = 0;
    for (int i = 0; i < 10; i++) {
        sum += a[i];
        if (a[i] % 3 == 0) sumDiv += a[i];
    }

    double media = sum / 10.0;

    cout << "Média: " << fixed << setprecision(1) << media << "\n";
    cout << "Divisíveis: " << sumDiv << "\n";
    return 0;
}