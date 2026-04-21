/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long valorMax;
    string moeda1;
    if (!(cin >> valorMax)) return 0;
    cin >> moeda1;

    vector<pair<string,long long>> itens(4);
    for (int i = 0; i < 4; i++) {
        string obj;
        long long v;
        cin >> obj >> v;
        itens[i] = {obj, v};
    }

    string moeda2;
    cin >> moeda2;

    auto okCurrency = [&](const string& m)->bool{
        return m == "real" || m == "iene";
    };

    if (!okCurrency(moeda1) || !okCurrency(moeda2)) {
        cout << "Nao conheco essa moeda, vamos comprar outra coisa...";
        return 0;
    }

    auto toReais = [&](long long amt, const string& m)->long double{
        if (m == "real") return (long double)amt;
        return (long double)amt * 0.03L;
    };

    long double maxReais = toReais(valorMax, moeda1);
    long double totalReais = 0.0L;
    for (auto &it : itens) totalReais += toReais(it.second, moeda2);

    if (maxReais + 1e-12L >= totalReais) {
        cout << "UHU, todo trabalho valeu a pena!";
    } else {
        cout << "Nao podemos comprar tudo, precisamos codar mais.";
    }
    return 0;
}