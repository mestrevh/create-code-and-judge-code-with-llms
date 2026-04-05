/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

double calcularSalario(double salarioMinimo, int pecas) {
    double salario = salarioMinimo;
    if (pecas > 30) {
        if (pecas <= 41) salario += (pecas - 30) * salarioMinimo * 0.03;
        else salario += (41 - 30) * salarioMinimo * 0.03 + (pecas - 41) * salarioMinimo * 0.05;
    }
    return salario;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double salarioMinimo;
    if (!(cin >> salarioMinimo)) return 0;

    vector<int> p(3);
    for (int i = 0; i < 3; i++) cin >> p[i];

    vector<double> s(3);
    for (int i = 0; i < 3; i++) s[i] = calcularSalario(salarioMinimo, p[i]);

    int total = p[0] + p[1] + p[2];
    double media = total / 3.0;
    double maior = max({s[0], s[1], s[2]});

    cout << fixed << setprecision(2);
    cout << "Salario 1: " << s[0] << "\n";
    cout << "Salario 2: " << s[1] << "\n";
    cout << "Salario 3: " << s[2] << "\n";
    cout << "Total de pecas fabricadas: " << total << "\n";
    cout << "Media de pecas fabricadas: " << media << "\n";
    cout << "Maior salario: " << maior << "\n";

    return 0;
}