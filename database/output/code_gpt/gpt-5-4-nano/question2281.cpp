/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int digitsCount(long long n) {
    if (n < 10) return 1;
    return 1 + digitsCount(n / 10);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;
    cout << digitsCount(n) << "\n";
    return 0;
}