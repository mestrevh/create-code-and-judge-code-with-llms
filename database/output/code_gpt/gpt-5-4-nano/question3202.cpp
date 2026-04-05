/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long custo, preco;
    if (!(cin >> custo >> preco)) return 0;

    long long q1 = (custo + preco - 1) / preco;
    long long custo_lucro23 = custo * 123;
    long long q2 = (custo_lucro23 + (preco - 1)) / preco;

    cout << q1 << "\n" << q2;
    return 0;
}