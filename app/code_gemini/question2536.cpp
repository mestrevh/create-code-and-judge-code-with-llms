/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <ios>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double salario, valor_emprestimo;
    int num_prestacoes;

    std::cin >> salario >> valor_emprestimo >> num_prestacoes;

    std::cout << "Digite o salario:" << std::endl;
    std::cout << "Digite o valor do emprestimo:" << std::endl;
    std::cout << "Digite o numero de prestacoes:" << std::endl;

    if (salario > 0 && valor_emprestimo > 0 && num_prestacoes > 0) {
        double valor_da_prestacao = valor_emprestimo / num_prestacoes;
        double limite_da_prestacao = salario * 0.30;
        if (valor_da_prestacao <= limite_da_prestacao) {
            std::cout << "O emprestimo pode ser concedido" << std::endl;
        } else {
            std::cout << "O emprestimo nao pode ser concedido" << std::endl;
        }
    } else {
        std::cout << "O emprestimo nao pode ser concedido" << std::endl;
    }

    return 0;
}
