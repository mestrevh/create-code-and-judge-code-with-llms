/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long F(long long X, long long Q, long long N) {
    if (X >= N) return X - N + X * Q;
    return F(X * Q, Q, N - X);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long X, Q, N;
    if (!(cin >> X >> Q >> N)) return 0;
    cout << F(X, Q, N) << "\n";
    return 0;
}