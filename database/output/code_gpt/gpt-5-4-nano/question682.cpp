/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int A;
        cin >> A;
        if (A <= 0 || A >= 180) {
            cout << "NAO\n";
            continue;
        }
        int n = 360 / A;
        if (n >= 3 && 360 % A == 0) cout << "SIM\n";
        else cout << "NAO\n";
    }
    return 0;
}