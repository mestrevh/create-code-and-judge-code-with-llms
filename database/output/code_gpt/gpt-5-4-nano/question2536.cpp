/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double salario, emprestimo;
    int n;
    cout << "Digite o salario: ";
    if (!(cin >> salario)) return 0;
    cout << "Digite o valor do emprestimo: ";
    cin >> emprestimo;
    cout << "Digite o numero de prestacoes: ";
    cin >> n;

    double prestacao = emprestimo / n;
    if (prestacao <= 0.30 * salario) {
        cout << "O emprestimo pode ser concedido";
    } else {
        cout << "O emprestimo nao pode ser concedido";
    }
    return 0;
}