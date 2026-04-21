/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, b;
    if (!(cin >> a)) return 0;
    if (!(cin >> b)) return 0;

    if (b <= a) cout << 0 << "\n";
    else cout << (b - a) << "\n";
    return 0;
}