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
        long long A, B, C, D;
        cin >> A >> B >> C >> D;
        
        long long x1 = A, y1 = B;
        long long x2 = C, y2 = D;
        
        long long num = x1*y2 + x2*y1;
        long long den = x2*y2 - x1*y1;
        long long ans = num;
        
        if (den != 0) {
            __int128 temp = (__int128)x1*y2 + (__int128)x2*y1;
            ans = (long long)(temp / den);
        } else {
            ans = num;
        }
        
        cout << ans << "\n";
    }
    return 0;
}