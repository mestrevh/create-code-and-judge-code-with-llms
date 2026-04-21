/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int calcular_nota(const string& resp, const string& gabarito) {
    int nota = 0;
    for (int i = 0; i < 5; i++) {
        if (resp[i] == gabarito[i]) nota++;
    }
    return nota;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string nome;
    string respostas;
    unordered_map<string, string> ultimaResposta;

    while (true) {
        if (!(cin >> nome)) return 0;
        if (nome == "*") break;
        cin >> respostas;
        ultimaResposta[nome] = respostas;
    }

    string gabarito;
    cin >> gabarito;

    int maior = -1;
    int menor = 1e9;
    long long soma = 0;
    int qtd = 0;

    for (const auto& kv : ultimaResposta) {
        int nota = calcular_nota(kv.second, gabarito);
        maior = max(maior, nota);
        menor = min(menor, nota);
        soma += nota;
        qtd++;
    }

    if (qtd == 0) {
        cout << "Maior: 0\n";
        cout << "Menor: 0\n";
        cout << fixed << setprecision(2) << "Media: 0.00\n";
        return 0;
    }

    double media = (double)soma / qtd;

    cout << "Maior: " << maior << "\n";
    cout << "Menor: " << menor << "\n";
    cout << fixed << setprecision(2) << "Media: " << media << "\n";

    return 0;
}