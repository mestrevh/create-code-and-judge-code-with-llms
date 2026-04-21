/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long P;
    while (cin >> P) {
        if (P == 0) break;

        long long n10 = P / 10;
        P %= 10;

        long long n5 = P / 5;
        P %= 5;

        long long n1 = P;

        long long total = n1 + n5 + n10;

        cout << total << "\n";
        cout << n1 << " " << n5 << " " << n10 << "\n";
    }
    return 0;
}