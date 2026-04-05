/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long dx = x1 - x2;
        long long dy = y1 - y2;
        ans += dx * dx + dy * dy;
    }
    cout << ans << "\n";
    return 0;
}