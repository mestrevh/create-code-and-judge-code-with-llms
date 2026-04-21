/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long multiplyRec(long long a, long long b) {
    if (b == 0) return 0;
    if (b > 0) return a + multiplyRec(a, b - 1);
    return -multiplyRec(a, -b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, b;
    if (!(cin >> a)) return 0;
    if (!(cin >> b)) return 0;
    
    cout << multiplyRec(a, b);
    return 0;
}