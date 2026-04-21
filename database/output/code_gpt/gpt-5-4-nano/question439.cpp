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

    double price = 19.90;
    double total = n * price;

    int groups = n / 15;
    double bonus = groups * 0.08 * total;
    double salary = 0.50 * total + bonus;

    cout << fixed << setprecision(2);
    cout << total << "\n" << bonus << "\n" << salary << "\n";
    return 0;
}