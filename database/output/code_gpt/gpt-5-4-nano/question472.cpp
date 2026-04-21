/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long idade;
    long long totalFraldas = 0;

    auto isNao = [&](string s) {
        for (char &c : s) c = tolower((unsigned char)c);
        string t;
        for (char c : s) if (c >= 'a' && c <= 'z') t.push_back(c);
        return t == "nao" || t == "não";
    };

    bool first = true;
    while (true) {
        if (!(cin >> idade)) break;
        string palavra;
        if (!(cin >> palavra)) break;
        bool continua = !isNao(palavra);
        long long porDia = (idade <= 2) ? 9 : 6;
        totalFraldas += porDia * 30;
        if (!continua) break;
    }

    const long long pacote = 100;
    long long qtdPacotes = totalFraldas / pacote;
    long long sobra = totalFraldas % pacote;
    if (sobra != 0) qtdPacotes++;

    long long fraldasSobra = (qtdPacotes * pacote) - totalFraldas;

    cout << qtdPacotes << "\n" << fraldasSobra << "\n";
    return 0;
}