/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string produto, sabor;
    int quantidade;

    std::cin >> produto >> sabor >> quantidade;

    double preco_unitario = 0.0;
    double taxa_entrega_por_item = 2.00;

    if (produto == "Pizza") {
        if (sabor == "CALABRESA" || sabor == "MARGUERITA") {
            preco_unitario = 20.60;
        } else {
            preco_unitario = 30.90;
        }
    } else if (produto == "Lasanha") {
        if (sabor == "QUEIJO") {
            preco_unitario = 18.00;
        } else if (sabor == "BOLONHESA") {
            preco_unitario = 23.00;
        }
    }

    double valor_total = (preco_unitario + taxa_entrega_por_item) * quantidade;

    std::cout << std::fixed << std::setprecision(2) << valor_total << std::endl;

    return 0;
}
