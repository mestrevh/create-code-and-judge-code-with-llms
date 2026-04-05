/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long soma3(long long a, long long b, long long c) {
    return a + b + c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    if (!(cin >> a)) return 0;
    cin >> b >> c;
    cout << soma3(a, b, c);
    return 0;
}