/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, int> food_values;
    food_values["Arroz"] = 25;
    food_values["Churrasco de Animal do Mar"] = 100;
    food_values["Paella Vestido de Camarao"] = 70;
    food_values["Massa de Tinta de Lula Rosa"] = 55;
    food_values["Mizu Mizu Doces"] = 15;

    int n_fome, n_pratos;
    std::cin >> n_fome >> n_pratos;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < n_pratos; ++i) {
        std::string prato;
        std::getline(std::cin, prato);
        if (food_values.count(prato)) {
            n_fome -= food_values[prato];
        }
    }

    if (n_fome > 0) {
        std::cout << "Pell, voe e traga mais comida ou a festa sera arruinada!\n";
    } else {
        std::cout << "Sucesso, vamos todos celebrar.\n";
    }

    return 0;
}
