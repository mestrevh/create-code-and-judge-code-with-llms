/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long rec(long long n, int t) {
    if (t == 0) return n;
    long long prev = rec(n, t - 1);
    if (t % 2 == 1) return prev + 3;
    return prev + (prev % 5);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    int T;
    if (!(cin >> N >> T)) return 0;
    cout << rec(N, T) << "\n";
    return 0;
}