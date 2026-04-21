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
    if (!(cin >> a >> b)) return 0;

    long long l = llabs(a / std::gcd(a, b) * b);
    if (l == 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long count = 0;
    for (long long x = l; x < 50; x += l) {
        if (x > 0) count++;
    }
    cout << count << "\n";
    return 0;
}