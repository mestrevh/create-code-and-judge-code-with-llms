/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long R, N;
    if (!(cin >> R >> N)) return 0;

    if (N < 1) {
        cout << "A somatoria da PA eh: 0";
        return 0;
    }

    long long k = (N - 1) / R;
    long long first = 1;
    long long last = N;
    long long sum = (k + 1) * (first + last) / 2;

    cout << "A somatoria da PA eh: " << sum;
    return 0;
}