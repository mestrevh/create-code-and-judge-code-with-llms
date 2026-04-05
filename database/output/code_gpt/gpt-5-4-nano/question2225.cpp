/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long M;
    if (!(cin >> M)) return 0;

    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    vector<string> cor = {"Verde", "Vermelho", "Roxo", "Amarelo"};
    vector<long long> vel = {80, 100, 120, 80};
    vector<long long> preco = {A, B, C, D};

    bool found = false;
    int best = -1;

    for (int i = 0; i < 4; i++) {
        if (preco[i] <= M) {
            if (!found) {
                found = true;
                best = i;
            } else {
                __int128 lhs = (__int128)vel[i] * preco[best];
                __int128 rhs = (__int128)vel[best] * preco[i];
                if (lhs > rhs) best = i;
                else if (lhs == rhs && i < best) best = i;
            }
        }
    }

    if (!found) {
        cout << "Acho que vou a pe :(";
    } else {
        cout << cor[best];
    }

    return 0;
}