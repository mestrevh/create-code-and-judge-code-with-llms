/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    if (N == 0) {
        cout << "Sem negociacoes por hoje!";
        return 0;
    }

    const double USD_TO_BRL = 5.17;

    struct Produto { string nome; double precoLoteUSD; };
    struct Frete { string continente; double taxaUSD; };

    unordered_map<int, Produto> produtos;
    produtos[701] = {"Abacaxi", 34.72};
    produtos[702] = {"Laranja", 34.72};
    produtos[703] = {"Banana", 28.90};
    produtos[704] = {"Cafe", 79.32};
    produtos[705] = {"Caju", 24.50};
    produtos[706] = {"Melancia", 19.60};
    produtos[707] = {"Soja", 45.10};
    produtos[708] = {"Trigo", 52.25};
    produtos[709] = {"Carne bovina", 68.40};
    produtos[710] = {"Carne suina", 61.80};
    produtos[711] = {"Trigo", 52.25};

    unordered_map<string, double> fretes;
    fretes["America"] = 150.00;
    fretes["Europa"] = 200.00;
    fretes["Africa"] = 180.00;
    fretes["Asia"] = 220.00;
    fretes["Oceania"] = 250.00;
    fretes["Americas"] = 150.00;

    for (int i = 0; i < N; i++) {
        string comprador, pais, continente;
        int cod, qtd;
        cin >> ws;
        getline(cin, comprador);
        getline(cin, pais);
        getline(cin, continente);
        cin >> cod >> qtd;

        auto itp = produtos.find(cod);
        if (itp == produtos.end()) {
            cout << "Operacao invalida!";
            if (i != N - 1) cout << "\n";
            continue;
        }

        double custoProduto = itp->second.precoLoteUSD * qtd;

        double taxaFreteUSD = 0.0;
        auto itf = fretes.find(continente);
        if (itf != fretes.end()) taxaFreteUSD = itf->second;

        double total = custoProduto + taxaFreteUSD;

        cout << comprador << "\n";
        cout << pais << "\n";
        cout << itp->second.nome << "\n";

        cout << fixed << setprecision(2);
        cout << "Valor do produto: U$ " << custoProduto << "\n";
        cout << "Valor do frete: U$ " << taxaFreteUSD << "\n";
        cout << "Valor total: U$ " << total;

        if (i != N - 1) cout << "\n";
    }

    return 0;
}