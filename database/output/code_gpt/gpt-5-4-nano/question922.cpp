/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double salario;
    if (!(cin >> salario)) return 0;

    double percentual;
    if (salario <= 280.0) percentual = 0.20;
    else if (salario <= 700.0) percentual = 0.15;
    else if (salario <= 1500.0) percentual = 0.10;
    else percentual = 0.05;

    double aumento = salario * percentual;
    double reajustado = salario + aumento;

    cout << "Informe o salario do colaborador:\n";
    cout << "Salario antes do reajuste: " << salario << "\n";
    cout << "Percentual de aumento aplicado: " << (percentual * 100.0) << "%\n";
    cout << "Valor do aumento: " << aumento << "\n";
    cout << "Salario com reajuste: " << reajustado;
    return 0;
}