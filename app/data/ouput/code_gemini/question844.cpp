/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int codigo, quantidade;
    double preco_unitario;

    std::cin >> codigo >> quantidade >> preco_unitario;

    if (codigo == 0) {
        std::cout << "nao tem compras\n";
        return 0;
    }

    int melhor_codigo = codigo;
    int melhor_quantidade = quantidade;
    double max_custo = static_cast<double>(quantidade) * preco_unitario;

    while (std::cin >> codigo >> quantidade >> preco_unitario && codigo != 0) {
        double custo_atual = static_cast<double>(quantidade) * preco_unitario;
        if (custo_atual > max_custo) {
            max_custo = custo_atual;
            melhor_codigo = codigo;
            melhor_quantidade = quantidade;
        }
    }

    std::cout << "Item mais caro\n";
    std::cout << "Codigo: " << melhor_codigo << "\n";
    std::cout << "Quantidade: " << melhor_quantidade << "\n";
    std::cout << "Custo: " << std::fixed << std::setprecision(2) << max_custo << "\n";

    return 0;
}
