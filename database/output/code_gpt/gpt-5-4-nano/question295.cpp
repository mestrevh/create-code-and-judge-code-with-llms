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
    if (!(cin >> x1 >> y1)) return 0;
    cin >> x2 >> y2;
    
    long double dx = (long double)x1 - (long double)x2;
    long double dy = (long double)y1 - (long double)y2;
    long double dist = sqrt(dx * dx + dy * dy);
    
    cout << fixed << setprecision(4) << (double)dist << "\n";
    return 0;
}