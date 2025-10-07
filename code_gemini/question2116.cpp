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

    std::string meat_option;
    std::cin >> meat_option;

    if (meat_option != "C" && meat_option != "BF" && meat_option != "BS") {
        std::cout << "Opção inválida." << std::endl;
        return 0;
    }

    char garlic_bread, adult_drinks, kids_drinks;
    int children, adults;
    std::cin >> garlic_bread >> adult_drinks >> kids_drinks >> children >> adults;

    double total_cost = 0.0;

    if (meat_option == "C") {
        double beef_kg = (0.2 * adults) + (0.2 * children);
        double chicken_kg = 0.1 * adults;
        double pork_kg = 0.1 * adults;
        total_cost += beef_kg * 32.00;
        total_cost += chicken_kg * 18.00;
        total_cost += pork_kg * 15.00;
    } else if (meat_option == "BF") {
        double beef_kg = (0.25 * adults) + (0.2 * children);
        double chicken_kg = 0.15 * adults;
        total_cost += beef_kg * 32.00;
        total_cost += chicken_kg * 18.00;
    } else { // BS
        double beef_kg = (0.25 * adults) + (0.2 * children);
        double pork_kg = 0.15 * adults;
        total_cost += beef_kg * 32.00;
        total_cost += pork_kg * 15.00;
    }

    if (adult_drinks == 'S') {
        total_cost += (double)adults * 2.0 * 8.00;
    }

    if (kids_drinks == 'S') {
        total_cost += (double)children * 0.5 * 6.00;
    }

    if (garlic_bread == 'N') {
        total_cost *= 0.98;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "R$: " << total_cost << std::endl;

    return 0;
}
