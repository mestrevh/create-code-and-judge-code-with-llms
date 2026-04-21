/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int capacidade;
    if (!(cin >> capacidade)) return 0;

    vector<string> nomes(capacidade);
    for (int i = 0; i < capacidade; i++) cin >> nomes[i];

    vector<double> saldos(capacidade, 0.0);

    auto idxOf = [&](const string& nome) -> int {
        for (int i = 0; i < capacidade; i++) {
            if (nomes[i] == nome) return i;
        }
        return -1;
    };

    string nome;
    while (cin >> nome) {
        if (nome == "FIM") break;
        char op;
        double val;
        cin >> op >> val;
        int idx = idxOf(nome);
        if (idx < 0) continue;
        if (op == 'C') saldos[idx] += val;
        else if (op == 'P') saldos[idx] -= val;
    }

    int acima = 0;
    int sem = 0;
    double soma = 0.0;

    for (int i = 0; i < capacidade; i++) {
        if (saldos[i] > 100.0) acima++;
        if (fabs(saldos[i]) < 1e-9) sem++;
        soma += saldos[i];
    }

    int maiorIdx = 0;
    for (int i = 1; i < capacidade; i++) {
        if (saldos[i] > saldos[maiorIdx]) maiorIdx = i;
    }

    cout << fixed << setprecision(0);
    cout << "Contas acima de 100 reais: " << acima << "\n";
    cout << "Contas sem dividas: " << sem << "\n";
    cout << "Soma das dividas: R$ " << fixed << setprecision(2) << soma << "\n";
    cout << "Maior divida: " << nomes[maiorIdx] << " - R$ " << fixed << setprecision(2) << saldos[maiorIdx] << "\n";

    return 0;
}