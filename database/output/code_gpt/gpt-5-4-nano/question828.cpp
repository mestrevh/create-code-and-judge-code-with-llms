/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double hora, horasMes;
    if (!(cin >> hora)) return 0;
    if (!(cin >> horasMes)) return 0;

    double salario = hora * horasMes;

    cout << "Informe quanto ganha por hora:\n";
    cout << "Informe a quantidade mensal de trabalho:\n";
    cout << "Resultado: " << salario;

    return 0;
}