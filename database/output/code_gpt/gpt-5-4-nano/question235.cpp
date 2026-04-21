/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> par(5), impar(5);
    int parSize = 0, imparSize = 0;

    auto flushPar = [&]() {
        for (int i = 0; i < parSize; i++) {
            cout << "par[" << i << "] = " << par[i] << "\n";
        }
        parSize = 0;
    };

    auto flushImpar = [&]() {
        for (int i = 0; i < imparSize; i++) {
            cout << "impar[" << i << "] = " << impar[i] << "\n";
        }
        imparSize = 0;
    };

    for (int k = 0; k < 15; k++) {
        long long x;
        if (!(cin >> x)) return 0;
        if (x % 2 == 0) {
            par[parSize++] = x;
            if (parSize == 5) flushPar();
        } else {
            impar[imparSize++] = x;
            if (imparSize == 5) flushImpar();
        }
    }

    for (int i = 0; i < imparSize; i++) {
        cout << "impar[" << i << "] = " << impar[i] << "\n";
    }
    for (int i = 0; i < parSize; i++) {
        cout << "par[" << i << "] = " << par[i] << "\n";
    }

    return 0;
}