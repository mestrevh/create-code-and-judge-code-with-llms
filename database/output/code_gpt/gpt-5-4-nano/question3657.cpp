/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, pair<double, double>> data;
    unordered_map<string, vector<double>> history;

    string code;
    while (cin >> code) {
        if (code == "fim" || code == "FIM") break;

        string desc;
        cin >> ws;
        getline(cin, desc);
        double valorCompra;
        long long qtd;
        cin >> valorCompra >> qtd;

        vector<double> h;
        h.push_back(valorCompra);
        history[code] = h;
        data[code] = {valorCompra, (double)qtd};
        string t;
        while (cin >> t) {
            if (t == "fim" || t == "FIM") {
                code = t;
                break;
            } else {
                double novoValor = stod(t);
                if ((int)history.size() && history.count(code)) {
                    auto &vh = history[code];
                    vh.push_back(novoValor);
                    if ((int)vh.size() > 10) vh.erase(vh.begin());
                }
            }
        }
        if (code == "fim" || code == "FIM") break;
    }

    bool firstOut = true;
    while (true) {
        if (!(cin >> code)) break;
        if (code == "fim" || code == "FIM") break;

        double valorAtual;
        cin >> valorAtual;

        auto it = history.find(code);
        if (it == history.end()) {
            if (!firstOut) cout << "\n";
            firstOut = false;
            cout << "Compra";
            continue;
        }

        auto &h = it->second;
        double soma = 0;
        for (double v : h) soma += v;
        double media = soma / h.size();
        double anterior = h.back();

        bool vende = (valorAtual >= media) || (valorAtual >= anterior);
        if (!firstOut) cout << "\n";
        firstOut = false;
        cout << (vende ? "Venda" : "Compra");

        h.push_back(valorAtual);
        if ((int)h.size() > 10) h.erase(h.begin());
    }

    return 0;
}