/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long mulRec(long long a, long long b) {
    if (b == 0 || a == 0) return 0;
    if (b == 1) return a;
    if (b == -1) return -a;
    bool neg = false;
    if (b < 0) {
        neg = !neg;
        b = -b;
    }
    if (a < 0) {
        neg = !neg;
        a = -a;
    }
    long long res = mulRec(a, b >> 1);
    res += res;
    if (b & 1) res += a;
    return neg ? -res : res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long A, B;
    while (cin >> A >> B) {
        cout << mulRec(A, B);
        if (!cin.eof()) cout << "\n";
    }
    return 0;
}