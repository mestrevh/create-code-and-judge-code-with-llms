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

    long long bestVal = LLONG_MIN;
    long long bestPos = -1;

    for (long long i = 0; i < N; i++) {
        long long x;
        cin >> x;
        if (i == 0 || x > bestVal) {
            bestVal = x;
            bestPos = i;
        }
    }

    cout << "o maior numero eh " << bestVal << ", e foi lido na posicao " << bestPos;
    return 0;
}