/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> numeros(5);
    vector<string> nomes(5), siglas(5);
    vector<long long> votos(5, 0);

    for (int i = 0; i < 5; i++) {
        if (!(cin >> numeros[i])) return 0;
        cin >> nomes[i];
        cin >> siglas[i];
    }

    unordered_map<int, int> idx;
    idx.reserve(16);
    for (int i = 0; i < 5; i++) idx[numeros[i]] = i;

    long long x;
    while (cin >> x) {
        if (x == 0) break;
        auto it = idx.find((int)x);
        if (it != idx.end()) votos[it->second]++;
    }

    for (int i = 0; i < 5; i++) {
        cout << siglas[i] << ' ' << numeros[i] << ' ' << nomes[i] << ": " << votos[i] << "\n";
    }

    return 0;
}