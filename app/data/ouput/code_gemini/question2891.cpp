/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double preco_compra, preco_venda;
    double total_compra = 0.0;
    double total_venda = 0.0;
    int lucro_menor_igual_10 = 0;
    int lucro_entre_10_20 = 0;
    int lucro_maior_igual_20 = 0;

    for (int i = 0; i < 10; ++i) {
        std::cout << "Digite o preco de compra:" << std::endl;
        std::cin >> preco_compra;
        std::cout << "Digite o preco de venda:" << std::endl;
        std::cin >> preco_venda;

        total_compra += preco_compra;
        total_venda += preco_venda;

        double percentual_lucro = ((preco_venda - preco_compra) / preco_compra) * 100.0;

        if (percentual_lucro <= 10.0) {
            lucro_menor_igual_10++;
        } else if (percentual_lucro < 20.0) {
            lucro_entre_10_20++;
        } else {
            lucro_maior_igual_20++;
        }
    }

    double percentual_lucro_total = ((total_venda - total_compra) / total_compra) * 100.0;

    std::cout << "Mercadorias com lucro menor ou igual a 10%: " << lucro_menor_igual_10 << std::endl;
    std::cout << "Mercadorias com lucro maior que 10% e menor que 20%: " << lucro_entre_10_20 << std::endl;
    std::cout << "Mercadorias com lucro maior ou igual a 20%: " << lucro_maior_igual_20 << std::endl;
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total de compra das mercadorias: R$ " << total_compra << std::endl;
    std::cout << "Total de venda das mercadorias: R$ " << total_venda << std::endl;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Percentual de lucro total: " << percentual_lucro_total << " %" << std::endl;

    return 0;
}
