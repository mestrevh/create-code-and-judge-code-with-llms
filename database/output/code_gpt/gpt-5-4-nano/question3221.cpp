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

    if (n == 0) {
        cout << 1;
        return 0;
    }

    if (n < 0) n = -n;

    int digits = 0;
    while (n > 0) {
        digits++;
        n /= 10;
    }

    cout << digits;
    return 0;
}