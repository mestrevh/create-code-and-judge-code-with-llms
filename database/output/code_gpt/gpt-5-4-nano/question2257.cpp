/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n;
    int x;
    if (!(cin >> n >> x)) return 0;

    if (n == 0) {
        cout << "nao";
        return 0;
    }

    while (n > 0) {
        int d = n % 10;
        if (d == x - 1 || d == x + 1) {
            cout << "sim";
            return 0;
        }
        n /= 10;
    }

    cout << "nao";
    return 0;
}