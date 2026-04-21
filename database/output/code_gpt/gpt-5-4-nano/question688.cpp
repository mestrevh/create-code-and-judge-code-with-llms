/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long A, B, C;
    if (!(cin >> A >> B >> C)) return 0;

    auto gcdll = [](long long x, long long y) {
        if (x < 0) x = -x;
        if (y < 0) y = -y;
        while (y) {
            long long t = x % y;
            x = y;
            y = t;
        }
        return x;
    };

    long long g = gcdll(A, B);
    cout << (C % g == 0 ? "S" : "N") << "\n";
    return 0;
}