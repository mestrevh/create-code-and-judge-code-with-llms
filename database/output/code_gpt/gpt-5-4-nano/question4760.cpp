/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long P1, C1, P2, C2;
    if (!(cin >> P1)) return 0;
    cin >> C1 >> P2 >> C2;

    if (P1 < 10 || P1 > 100 || C1 < 10 || C1 > 100 || P2 < 10 || P2 > 100 || C2 < 10 || C2 > 100) {
        cout << "Restricao violada";
        return 0;
    }

    long long left = P1 * C1;
    long long right = P2 * C2;

    if (left == right) {
        cout << "Gangorra equilibrada";
    } else if (left > right) {
        cout << "Gangorra desequilibrada para a direita";
    } else {
        cout << "Gangorra desequilibrada para a esquerda";
    }
    return 0;
}