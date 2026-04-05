/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int faltas;
    if (!(cin >> faltas)) return 0;
    vector<double> notas(5);
    for (int i = 0; i < 5; i++) cin >> notas[i];

    double soma = 0.0;
    for (double x : notas) soma += x;
    double media = soma / 5.0;

    if (faltas <= 5 && media >= 7.0) cout << "APROVADO";
    else cout << "REPROVADO";
    return 0;
}