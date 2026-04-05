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

    for (long long i = 1; i <= n; i++) {
        long long spaces = n - i;
        long long xs = 2 * i;
        for (long long s = 0; s < spaces; s++) cout << ' ';
        for (long long k = 0; k < xs; k++) cout << 'X';
        cout << "\n";
    }

    long long stem = n / 2;
    long long center = n;
    for (long long i = 0; i < stem; i++) {
        for (long long s = 0; s < center - 1; s++) cout << ' ';
        cout << "XX\n";
    }

    return 0;
}