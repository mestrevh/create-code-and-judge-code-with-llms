/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    int modulo = 9;
    int sumDigits = 0;
    for (char c : n) sumDigits = (sumDigits + (c - '0')) % modulo;

    long long total = (sumDigits * (k % modulo)) % modulo;
    int ans = (total == 0 ? 9 : (int)total);
    if (n.size() == 1 && k == 1) ans = n[0] - '0';
    if (ans == 9 && (n.size() == 1 && (n[0] - '0') == 0)) ans = 0;

    cout << ans << "\n";
    return 0;
}