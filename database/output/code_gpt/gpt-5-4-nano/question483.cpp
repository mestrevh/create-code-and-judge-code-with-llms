/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long simCount = 0, naoCount = 0, nuloCount = 0;
    string voto;

    while (cin >> voto) {
        for (char &c : voto) c = (char)tolower((unsigned char)c);
        if (voto == "encerrar") break;
        if (voto == "sim") simCount++;
        else if (voto == "nao") naoCount++;
        else if (voto == "nulo") nuloCount++;
    }

    if (simCount > (naoCount + nuloCount)) cout << "COM FOGOS\n";
    else cout << "SEM FOGOS\n";

    return 0;
}