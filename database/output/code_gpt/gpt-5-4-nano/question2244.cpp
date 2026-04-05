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

    int winner = -1;
    for (int i = 1; i <= N; i++) {
        int ticket;
        cin >> ticket;
        if (ticket == i) winner = ticket;
    }

    cout << "o ingresso de numero " << winner << " foi sorteado";
    return 0;
}