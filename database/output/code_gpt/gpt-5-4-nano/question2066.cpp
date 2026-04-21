/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;
    long long sum = 0;
    for (long long i = 0; i < N; i++) {
        long long x;
        cin >> x;
        sum += x;
    }
    cout << sum;
    return 0;
}