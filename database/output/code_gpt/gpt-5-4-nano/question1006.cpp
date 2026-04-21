/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    while (cin >> x) {
        if (x == 0) break;
        long long a = (x - 1) / 2;
        long long b = (x + 1) / 2;
        cout << b * b << " - " << a * a << "\n";
    }
    return 0;
}