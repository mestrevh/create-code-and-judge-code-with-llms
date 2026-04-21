/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long gcdRec(long long a, long long b) {
    if (b == 0) return a >= 0 ? a : -a;
    return gcdRec(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    for (int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        long long r = gcdRec(a, b);
        cout << "MDC(" << a << "," << b << ") = " << r << "\n";
    }
    return 0;
}