/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C, D;
    long long S, M, Y;
    if (!(cin >> A >> B >> C >> D)) return 0;

    long long saques = A, manjus = B, yakitoris = C, pessoas = D;

    long long coposSaquesNec = pessoas * 4;
    long long manjusNec = pessoas * 5;
    long long yakitorisNec = pessoas * 3;

    long long faltSaques = max(0LL, coposSaquesNec - saques);
    long long faltManjus = max(0LL, manjusNec - manjus);
    long long faltYak = max(0LL, yakitorisNec - yakitoris);

    bool fS = faltSaques > 0;
    bool fM = faltManjus > 0;
    bool fY = faltYak > 0;

    if (!fS && !fM && !fY) {
        cout << "Partiu Festa do Japa!" << "\n";
        return 0;
    }

    if (fS && fM && fY) {
        cout << "Partiu Festa do Japa...Japacama" << "\n";
        return 0;
    }

    vector<pair<long long,string>> faltas;
    if (fS) faltas.push_back({faltSaques, "saques"});
    if (fM) faltas.push_back({faltManjus, "manjus"});
    if (fY) faltas.push_back({faltYak, "yakitoris"});

    if (faltas.size() == 1) {
        cout << "Faltaram " << faltas[0].first << " " << faltas[0].second << "\n";
    } else {
        cout << "Faltaram " << faltas[0].first << " " << faltas[0].second
             << " e " << faltas[1].first << " " << faltas[1].second << "\n";
    }

    return 0;
}