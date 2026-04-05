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

    if (N == 0) {
        cout << "NULO\n";
    } else {
        string sign = (N > 0) ? "POSITIVO" : "NEGATIVO";
        string parity = (llabs(N) % 2 == 0) ? "PAR" : "IMPAR";
        cout << sign << ' ' << parity << '\n';
    }
    return 0;
}