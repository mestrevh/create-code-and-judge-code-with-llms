/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int contar_vogais(const string& vogais, const string& frase) {
    array<bool, 256> isV{};
    for (unsigned char c : vogais) isV[c] = true;
    int cnt = 0;
    for (unsigned char c : frase) if (isV[c]) cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    string vogais;
    string dummy;
    getline(cin, dummy);

    while (T--) {
        getline(cin, vogais);
        string frase;
        getline(cin, frase);
        cout << contar_vogais(vogais, frase) << "\n";
    }
    return 0;
}