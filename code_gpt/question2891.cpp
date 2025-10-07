/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::vector<double> compra(10), venda(10);
    int menor_10 = 0, entre_10_20 = 0, maior_20 = 0;
    double total_compra = 0, total_venda = 0;

    for (int i = 0; i < 10; ++i) {
        std::cout << "Digite o preco de compra:\n";
        std::cin >> compra[i];
        std::cout << "Digite o preco de venda:\n";
        std::cin >> venda[i];

        double lucro = (venda[i] - compra[i]) / compra[i] * 100;
        if (lucro <= 10) menor_10++;
        else if (lucro > 10 && lucro < 20) entre_10_20++;
        else if (lucro >= 20) maior_20++;

        total_compra += compra[i];
        total_venda += venda[i];
    }

    double percentual_lucro_total = ((total_venda - total_compra) / total_compra) * 100;

    std::cout << "Mercadorias com lucro menor ou igual a 10%: " << menor_10 << "\n";
    std::cout << "Mercadorias com lucro maior que 10% e menor que 20%: " << entre_10_20 << "\n";
    std::cout << "Mercadorias com lucro maior ou igual a 20%: " << maior_20 << "\n";
    std::cout << "Total de compra das mercadorias: R$ " << std::fixed << std::setprecision(2) << total_compra << "\n";
    std::cout << "Total de venda das mercadorias: R$ " << std::fixed << std::setprecision(2) << total_venda << "\n";
    std::cout << "Percentual de lucro total: " << std::fixed << std::setprecision(4) << percentual_lucro_total << " %\n";

    return 0;
}
