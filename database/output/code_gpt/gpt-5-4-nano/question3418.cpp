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

    long long x0 = 1, y0 = 0;
    long long x1 = 0, y1 = 1;

    while (b != 0) {
        long long q = a / b;
        long long r = a - q * b;

        long long x2 = x0 - q * x1;
        long long y2 = y0 - q * y1;

        a = b;
        b = r;
        x0 = x1; y0 = y1;
        x1 = x2; y1 = y2;
    }

    long long g = a;
    long long c1 = x0;
    long long c2 = -y0;

    cout << c1 << "*"+to_string(b==0?0:0) ; 
    return 0;
}