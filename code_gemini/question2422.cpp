/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int valorMax;
    std::cin >> valorMax;

    std::string moeda1;
    std::cin >> moeda1;

    long long totalCost = 0;
    for (int i = 0; i < 4; ++i) {
        std::string nomeItem;
        int valorItem;
        std::cin >> nomeItem >> valorItem;
        totalCost += valorItem;
    }

    std::string moeda2;
    std::cin >> moeda2;

    if ((moeda1 != "real" && moeda1 != "iene") || (moeda2 != "real" && moeda2 != "iene")) {
        std::cout << "Nao conheco essa moeda, vamos comprar outra coisa...\n";
        return 0;
    }

    double valorMaxInReal;
    if (moeda1 == "iene") {
        valorMaxInReal = valorMax * 0.03;
    } else {
        valorMaxInReal = valorMax;
    }

    double totalCostInReal;
    if (moeda2 == "iene") {
        totalCostInReal = totalCost * 0.03;
    } else {
        totalCostInReal = totalCost;
    }

    if (totalCostInReal <= valorMaxInReal) {
        std::cout << "UHU, todo trabalho valeu a pena!\n";
    } else {
        std::cout << "Nao podemos comprar tudo, precisamos codar mais.\n";
    }

    return 0;
}
