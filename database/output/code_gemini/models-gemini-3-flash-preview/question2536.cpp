/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double salario, emprestimo;
    int prestacoes;

    while (cin >> salario >> emprestimo >> prestacoes) {
        cout << "Digite o salario:\n";
        cout << "Digite o valor do emprestimo:\n";
        cout << "Digite o numero de prestacoes:\n";

        if (salario <= 0 || emprestimo <= 0 || prestacoes <= 0) {
            cout << "O emprestimo nao pode ser concedido" << endl;
        } else {
            double valor_prestacao = emprestimo / (double)prestacoes;
            double limite = salario * 0.3;

            if (valor_prestacao <= limite) {
                cout << "O emprestimo pode ser concedido" << endl;
            } else {
                cout << "O emprestimo nao pode ser concedido" << endl;
            }
        }
    }

    return 0;
}