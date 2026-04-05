/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool readPositiveDouble(double &x) {
    string s;
    if (!(cin >> s)) return false;
    try {
        x = stod(s);
    } catch (...) {
        return false;
    }
    return x > 0;
}

static void readValidDimensions(double dim[3]) {
    for (int i = 0; i < 3; ) {
        double x;
        if (!readPositiveDouble(x)) return;
        if (x > 0) {
            dim[i++] = x;
        } else {
            for (int j = 0; j < 3; j++) dim[j] = 0;
            i = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double peso;
    if (!(cin >> peso)) return 0;

    while (peso <= 0) {
        cout << "Peso invalido!\n";
        if (!(cin >> peso)) return 0;
    }
    cout << "Peso valido!\n";

    double d[3] = {0,0,0};
    while (true) {
        for (int i = 0; i < 3; i++) d[i] = 0;
        bool ok = true;
        for (int i = 0; i < 3; i++) {
            double x;
            if (!(cin >> x)) return 0;
            if (x <= 0) { ok = false; break; }
            d[i] = x;
        }
        if (!ok) {
            cout << "Dimensoes invalidas!\n";
            continue;
        }
        cout << "Dimensoes validas!\n";
        break;
    }

    double pmax = 500.0;
    double maiorDim = max({d[0], d[1], d[2]});
    double somaDims = d[0] + d[1] + d[2];

    if (peso > pmax || maiorDim > 28.0 || somaDims > 52.0) {
        cout << "Este pacote nao atende os limites para envio no caixa de autoatendimento, dirija-se ao balcao de atendimento para posta-lo!";
        return 0;
    }

    auto round2 = [&](double v) {
        return floor(v * 100.0 + 0.5) / 100.0;
    };

    double pesoG = peso;
    double precoPeso = pesoG * 0.004;
    double precoTam = somaDims * 0.01;
    double C = precoPeso + precoTam;

    cout << fixed << setprecision(2);
    cout << "Custo total do envio: R$ " << round2(C);
    return 0;
}