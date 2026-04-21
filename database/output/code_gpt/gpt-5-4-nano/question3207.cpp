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

    bool neg = n < 0;
    long long x = llabs(n);

    int a = (int)(x / 100);
    int b = (int)((x / 10) % 10);
    int c = (int)(x % 10);

    long long r = (long long)c * 100 + (long long)b * 10 + a;
    if (neg) r = -r;

    cout << r;
    return 0;
}