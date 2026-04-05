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

    if (N == 1) cout << "Bulbassauro";
    else if (N == 2) cout << "Charmander";
    else if (N == 3) cout << "Squirtle";

    return 0;
}