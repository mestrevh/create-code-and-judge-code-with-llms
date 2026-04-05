/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long x, y;
    if (!(cin >> x >> y)) return 0;

    if (x <= y) {
        for (long long i = x; i <= y; i++) {
            if (i != x) cout << "\n";
            cout << i;
        }
    } else {
        for (long long i = x; i >= y; i--) {
            if (i != x) cout << "\n";
            cout << i;
        }
    }
    return 0;
}