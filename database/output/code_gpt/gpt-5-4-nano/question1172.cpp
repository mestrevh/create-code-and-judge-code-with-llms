/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;

    if (n < 1000 || n > 9999) {
        cout << "Charmander derrotado";
        return 0;
    }

    long long A = n / 1000;
    long long B = (n / 100) % 10;
    long long C = (n / 10) % 10;
    long long D = n % 10;

    long long AB = 10 * A + B;
    long long CD = 10 * C + D;
    long long EF = AB + CD;

    if (EF < 10 || EF > 99) {
        cout << "Charmander derrotado";
        return 0;
    }

    long long sq = EF * EF;
    if (sq == n) cout << "Charmander vitorioso";
    else cout << "Charmander derrotado";

    return 0;
}