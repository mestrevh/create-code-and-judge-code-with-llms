/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    while (cin >> n) {
        if (n == -1) break;
        long long fact = 1;
        for (long long i = 2; i <= n; i++) fact *= i;
        cout << fact << "\n";
    }
    return 0;
}