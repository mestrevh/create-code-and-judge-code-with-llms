/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Paciente {
    string nome;
    double peso;
    double altura;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<Paciente> v;
    v.reserve(n);

    string line;
    getline(cin, line);

    for (int i = 0; i < n; i++) {
        string nome;
        getline(cin, nome);
        double peso, altura;
        cin >> peso >> altura;
        getline(cin, line);

        v.push_back({nome, peso, altura});
    }

    auto classificacao = [](double imc) -> string {
        if (imc < 18.5) return "Baixo peso";
        if (imc <= 24.9) return "Peso normal";
        if (imc <= 29.9) return "Sobrepeso";
        if (imc <= 34.9) return "Obesidade grau I";
        if (imc <= 39.9) return "Obsidade grau II";
        if (imc >= 40.0) return "Obesidade grau III";
        return "";
    };

    for (const auto& p : v) {
        double imc = p.peso / (p.altura * p.altura);
        cout << p.nome << ":\n" << classificacao(imc) << "\n\n";
    }

    return 0;
}