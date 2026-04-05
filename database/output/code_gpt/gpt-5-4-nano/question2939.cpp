/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X;
    if (!(cin >> X)) return 0;
    long long A, B, C;
    cin >> A >> B >> C;

    long long combat = (A + B - C) / 2;

    if (combat > X) cout << "O Pokemon pode ser derrotado!";
    else cout << "Melhor nao arriscar";

    return 0;
}