/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<long long> pares, impares;
    pares.reserve(N);
    impares.reserve(N);

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        if (x % 2 == 0) pares.push_back(x);
        else impares.push_back(x);
    }

    for (size_t i = 0; i < pares.size(); i++) {
        cout << "pares[" << i << "] = " << pares[i] << "\n";
    }
    for (size_t i = 0; i < impares.size(); i++) {
        cout << "impares[" << i << "] = " << impares[i] << "\n";
    }

    return 0;
}