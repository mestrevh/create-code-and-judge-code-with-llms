/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

string inverter(const string& s) {
    string r = s;
    reverse(r.begin(), r.end());
    return r;
}

string tratramento(const string& local, const string& tipo, const string& jogador) {
    if (local == "c") {
        return inverter(jogador);
    }
    if (tipo == "1") {
        if (jogador.empty()) return jogador;
        string res = jogador;
        res += string(5, jogador.back());
        return res;
    }
    return jogador;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string local, tipo;
    if (!(cin >> local >> tipo)) return 0;

    string jogador;
    getline(cin, jogador);
    if (!jogador.empty() && jogador[0] == ' ') jogador.erase(jogador.begin());

    cout << tratramento(local, tipo, jogador);
    return 0;
}