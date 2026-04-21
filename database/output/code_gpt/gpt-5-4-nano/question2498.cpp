/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    int n = (int)s.size();
    int mid = n / 2;
    long long a = 0, b = 0;

    for (int i = 0; i < mid; i++) a += s[i] - '0';
    for (int i = mid; i < n; i++) b += s[i] - '0';

    cout << (a == b ? "True" : "False");
    return 0;
}