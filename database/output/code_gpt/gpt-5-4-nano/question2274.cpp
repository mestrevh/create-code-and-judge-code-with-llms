/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, D;
    if (!(cin >> C >> D)) return 0;

    string vencedor;
    long long melhor = -1;

    for (int i = 0; i < C; i++) {
        string nome;
        long long TL, DO, TO;
        cin >> nome >> TL >> DO >> TO;

        long long obst = 0;
        for (long long pos = DO; pos <= D; pos += DO) obst++;

        long long total = TL * 60 + obst * TO;

        if (i == 0 || total < melhor) {
            melhor = total;
            vencedor = nome;
        }
    }

    cout << vencedor << " venceu a corrida em " << melhor << " segundos!";
    return 0;
}