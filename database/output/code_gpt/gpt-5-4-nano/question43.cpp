/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    if (a == b && b == c) {
        cout << 1 << "\n";
    } else if (a != b && a != c && b != c) {
        cout << 2 << "\n";
    } else {
        cout << 3 << "\n";
    }
    return 0;
}