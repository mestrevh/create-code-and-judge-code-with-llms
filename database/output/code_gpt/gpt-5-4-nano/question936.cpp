/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Digite um numero inteiro:\n";
    long long n;
    if (!(cin >> n)) return 0;

    if (n < 0) {
        cout << "Fatorial: 1";
        return 0;
    }

    __int128 res = 1;
    for (long long i = 2; i <= n; ++i) res *= i;

    string out;
    if (res == 0) out = "0";
    else {
        while (res > 0) {
            int digit = (int)(res % 10);
            out.push_back(char('0' + digit));
            res /= 10;
        }
        reverse(out.begin(), out.end());
    }

    cout << "Fatorial: " << out;
    return 0;
}