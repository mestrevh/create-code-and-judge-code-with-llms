/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double salario, emprestimo;
    int prestacoes;
    
    cout << "Digite o salario:\n";
    cin >> salario;
    cout << "Digite o valor do emprestimo:\n";
    cin >> emprestimo;
    cout << "Digite o numero de prestacoes:\n";
    cin >> prestacoes;

    if (salario <= 0 || emprestimo <= 0 || prestacoes <= 0) {
        cout << "Valores invalidos!" << endl;
        return 0;
    }

    double parcelas = emprestimo / prestacoes;
    if (parcelas <= (salario * 0.3)) {
        cout << "O emprestimo pode ser concedido" << endl;
    } else {
        cout << "O emprestimo nao pode ser concedido" << endl;
    }

    return 0;
}
