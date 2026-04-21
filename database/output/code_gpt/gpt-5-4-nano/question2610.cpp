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

    if (N < 0) {
        cout << "O valor informado para N foi negativo";
        return 0;
    }
    if (N == 0) {
        cout << "Lista vazia - O valor de S eh zero";
        return 0;
    }

    vector<long long> A(N);
    for (long long i = 0; i < N; i++) cin >> A[i];

    long long S = 0;
    long long i = 0, j = N - 1;
    while (i < j) {
        long long d = A[i] - A[j];
        S += d * d;
        i++;
        j--;
    }
    cout << S;
    return 0;
}