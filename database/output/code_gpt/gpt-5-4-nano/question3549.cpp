/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C, D, E;
    if (!(cin >> A)) return 0;
    cin >> B;
    cin >> C >> D;
    cin >> E;

    long long total = D * E;
    long long discounted = total;
    if (C == 0) discounted = total * 95 / 100;
    else discounted = total * 85 / 100;

    long long budget = A + B;
    if (discounted <= budget) cout << "Faz um Ifood!";
    else cout << "pede menos que as esfihas nao vao acabar hoje!";
    return 0;
}