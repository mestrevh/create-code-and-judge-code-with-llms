/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sociosAtendidos = 0;
    int brindesConcedidos = 0;
    long long totalCentavos = 0;

    auto toMoney = [&](int priceSocio, int priceNao) -> int {
        return priceSocio;
    };

    for (int i = 0; i < 5; i++) {
        string tamanho, lavagem, tipo;
        if (!getline(cin, tamanho)) return 0;
        while (tamanho.size() == 0 && cin) {
            getline(cin, tamanho);
        }
        getline(cin, lavagem);
        getline(cin, tipo);

        auto norm = [&](string s) {
            for (char &c : s) if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
            return s;
        };
        tamanho = norm(tamanho);
        lavagem = norm(lavagem);
        tipo = norm(tipo);

        bool eSocio = (tipo.find("socio") != string::npos);
        bool comCera = (lavagem.find("cera") != string::npos);
        bool pequeno = (tamanho.find("pequeno") != string::npos);

        int priceSocio = 0, priceNao = 0;
        if (pequeno) {
            if (comCera) { priceSocio = 30; priceNao = 40; }
            else { priceSocio = 20; priceNao = 30; }
        } else {
            if (comCera) { priceSocio = 60; priceNao = 80; }
            else { priceSocio = 40; priceNao = 50; }
        }

        int price = eSocio ? priceSocio : priceNao;
        totalCentavos += (long long)price * 100;

        if (eSocio) sociosAtendidos++;
        if (comCera) brindesConcedidos++;
    }

    cout << sociosAtendidos << "\n";
    cout << brindesConcedidos << "\n";
    cout << fixed << setprecision(2) << (totalCentavos / 100.0) << "\n";
    return 0;
}