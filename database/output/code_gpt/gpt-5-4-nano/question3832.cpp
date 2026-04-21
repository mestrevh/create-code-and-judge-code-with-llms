/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    if (!(cin >> N >> M)) return 0;

    if (N < M) {
        cout << "Pedro vai ter que fugir\n";
        return 0;
    }

    long long sobra = N - M;
    if (sobra > 0) cout << "Pegou mais\n";
    cout << "Esta pago\n";
    cout << "Sobrou " << sobra << "\n";
    return 0;
}