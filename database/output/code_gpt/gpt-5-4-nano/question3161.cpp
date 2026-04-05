/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long x1, y1, x2, y2;
    if (!(cin >> x1 >> y1 >> x2 >> y2)) return 0;

    long long dx = x1 - x2;
    long long dy = y1 - y2;
    long long dist2 = dx * dx + dy * dy;

    long long ans = llround(sqrt((long double)dist2));
    cout << ans;
    return 0;
}