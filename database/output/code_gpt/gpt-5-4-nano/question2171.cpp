/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long modRec(long long x, long long y) {
    if (y == 0) return -1;
    long long ax = llabs(x), ay = llabs(y);
    if (ax < ay) return ax;
    return modRec(ax - ay, ay);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long x, y;
    if (!(cin >> x >> y)) return 0;
    cout << modRec(x, y) << "\n";
    return 0;
}