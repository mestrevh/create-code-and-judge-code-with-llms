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

    long long first = 2 * (N - 1) * (N - 1) + 1;
    long long last = first + 2 * (N - 1) * 2;
    long long a = last - 4 * (N - 1);
    long long b = last - 2 * (N - 1);
    long long c = last;

    long long sum = a + b + c;
    cout << sum << "\n";
    return 0;
}