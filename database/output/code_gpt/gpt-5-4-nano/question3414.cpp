/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long A, B;
    if (!(cin >> A >> B)) return 0;
    long long d = llabs(A - B);
    long long a = d / 2;
    if (a * 2 == d) {
        cout << a << "\n";
        return 0;
    }
    
    long long best = (long long)4e18;
    for (long long x = 0; x * 2 <= d + 6; x++) {
        long long rem = d - 2 * x;
        if (rem < 0) break;
        if (rem % 3 == 0) {
            long long y = rem / 3;
            best = min(best, x + y);
        }
    }
    cout << best << "\n";
    return 0;
}