/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    long long y = 0;
    long long p = 1;
    while (p * 3 <= N) {
        p *= 3;
        y++;
    }

    unsigned long long fact = 1;
    for (long long i = 2; i <= y; i++) fact *= (unsigned long long)i;

    cout << fact;
    return 0;
}