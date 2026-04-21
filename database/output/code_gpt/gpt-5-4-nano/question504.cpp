/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long sum = 0;
    for (int i = 0; i < 5; i++) {
        long long x;
        if (!(cin >> x)) return 0;
        if (x % 3 == 0) sum += factorial((int)x);
    }
    cout << sum;
    return 0;
}