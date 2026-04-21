/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double x;
    if (!(cin >> x)) return 0;
    double ans = pow(x, 0.25);
    cout << fixed << setprecision(10) << ans;
    return 0;
}