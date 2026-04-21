/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;

    long long dozens = n / 12;
    long long rem = n % 12;

    double price_per_orange = 8.35 / 12.0;
    double total = dozens * 8.35 + rem * price_per_orange;

    cout << dozens << "\n";
    cout << fixed << setprecision(2) << total << "\n";
    return 0;
}