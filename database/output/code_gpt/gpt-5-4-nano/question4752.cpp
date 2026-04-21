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
        long long area1 = A * B;
        long long area2 = C * D;
        cout << max(area1, area2);
        if (T) cout << "\n";
    }
    return 0;
}