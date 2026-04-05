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
        unsigned long long a, b;
        unsigned int m;
        cin >> a >> b >> m;
        unsigned long long am = a % m;
        unsigned long long bm = b % m;
        __int128 prod = (__int128)am * (__int128)bm;
        unsigned long long ans = (unsigned long long)(prod % m);
        cout << ans << "\n";
    }
    return 0;
}