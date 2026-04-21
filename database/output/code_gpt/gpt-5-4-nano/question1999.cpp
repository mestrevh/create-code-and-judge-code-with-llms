/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> gabarito(n);
    for (int i = 0; i < n; i++) cin >> gabarito[i];

    if ((int)gabarito.size() < n) {
        cout << "Erro: gabarito menor que o tamanho desejado\n";
        return 0;
    }

    vector<string> resposta(n);
    string token;
    while (true) {
        if (!(cin >> token)) break;
        if (token == "sair") break;
        resposta[0] = token;
        for (int i = 1; i < n; i++) {
            if (!(cin >> resposta[i])) return 0;
        }

        int acertos = 0;
        for (int i = 0; i < n; i++) {
            if (resposta[i] == gabarito[i]) acertos++;
        }

        double percent = (n == 0) ? 0.0 : (100.0 * acertos / n);
        cout << "Percentual de acertos: " << fixed << setprecision(1) << percent << "\n";
    }

    return 0;
}