/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, C;
    if (!(cin >> N >> C)) return 0;

    long long cur = 0;
    bool exceeded = false;

    for (long long i = 0; i < N; i++) {
        long long S, E;
        cin >> S >> E;
        cur += E;
        cur -= S;
        if (cur > C) exceeded = true;
    }

    if (exceeded) cout << "Selvagens sao dificeis de ensinar.";
    else cout << "Viva a conscientizacao.";

    return 0;
}