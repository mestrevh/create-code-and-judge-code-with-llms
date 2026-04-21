/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double ipva, taxa;
    if (!(cin >> ipva >> taxa)) return 0;

    double total = ipva * 0.95 + taxa;
    cout << fixed << setprecision(2) << total << "\n";
    return 0;
}