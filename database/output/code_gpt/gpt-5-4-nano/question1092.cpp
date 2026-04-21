/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int homens = 0, mulheres = 0;
    double somaHomens = 0.0, somaMulheres = 0.0;
    double maiorSalario = -1.0;
    char sexoMaior = 'm';

    for (int i = 0; i < 10; i++) {
        char sexo;
        double salario;
        cin >> sexo;
        cin >> salario;

        if (sexo == 'm') {
            homens++;
            somaHomens += salario;
        } else {
            mulheres++;
            somaMulheres += salario;
        }

        if (salario > maiorSalario) {
            maiorSalario = salario;
            sexoMaior = sexo;
        }
    }

    double mediaHomens = homens ? somaHomens / homens : 0.0;
    double mediaTotal = (homens + mulheres) ? (somaHomens + somaMulheres) / (homens + mulheres) : 0.0;

    cout << homens << "\n";
    cout << mulheres << "\n";
    cout << fixed << setprecision(1) << mediaTotal << "\n";
    cout << sexoMaior << "\n";
    cout << fixed << setprecision(1) << mediaHomens << "\n";

    return 0;
}