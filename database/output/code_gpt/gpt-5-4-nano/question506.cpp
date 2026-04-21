/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string passeio, residente;
    long long totalCents = 0;
    long long qtdMergulho = 0;

    auto toLower = [&](string s) {
        for (char &c : s) c = (char)tolower((unsigned char)c);
        return s;
    };

    while (true) {
        if (!(cin >> passeio)) break;
        string p = toLower(passeio);

        int preco = -1;
        if (p == "mergulho") preco = 50;
        else if (p == "barco") preco = 65;
        else if (p == "buggy") preco = 90;
        else break;

        cin >> residente;
        string r = toLower(residente);

        bool isJP = (r == "sim");
        int valor = preco;
        if (isJP) valor = (int)round(preco * 0.6);

        totalCents += (long long)valor * 100;
        if (p == "mergulho") qtdMergulho++;
    }

    cout << qtdMergulho << "\n";
    cout << fixed << setprecision(2) << (totalCents / 100.0) << "\n";
    return 0;
}