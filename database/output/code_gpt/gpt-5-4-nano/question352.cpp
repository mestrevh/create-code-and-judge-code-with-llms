/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long mdc(long long a, long long b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, b;
    if (!(cin >> a >> b)) return 0;
    cout << mdc(a, b) << "\n";
    return 0;
}