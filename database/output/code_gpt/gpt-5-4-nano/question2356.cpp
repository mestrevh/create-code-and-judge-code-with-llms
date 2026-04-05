/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> tickets;
    long long x;
    while (cin >> x) {
        if (x == -1) break;
        tickets.push_back(x);
    }

    long long K;
    if (!(cin >> K)) return 0;

    for (size_t i = 0; i < tickets.size(); i++) {
        if (tickets[i] == K) {
            cout << "O bilhete sorteado e o " << K << " e esta no carrinho " << (i + 1);
            return 0;
        }
    }
    cout << "Nenhum carrinho foi sorteado";
    return 0;
}