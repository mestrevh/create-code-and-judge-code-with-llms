/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long maxSubtractions(long long X, long long Y) {
    if (Y == 0) return 0;
    return X / Y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long X, Y;
    if (!(cin >> X >> Y)) return 0;
    cout << maxSubtractions(X, Y) << "\n";
    return 0;
}