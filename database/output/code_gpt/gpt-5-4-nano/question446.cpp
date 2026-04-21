/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;

    long long groups = n / 3;
    long long rem = n % 3;

    long long paid = groups * 2 + rem;
    double total = paid * 2.20;

    cout << fixed << setprecision(2) << total << "\n";
    return 0;
}