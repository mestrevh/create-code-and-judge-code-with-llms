/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int d;
    std::cin >> d;

    long long best_damage = -1;
    int best_element_num = -1;
    int best_increase_percent = -1;

    for (int i = 1; i <= n; ++i) {
        int k, b;
        std::cin >> k >> b;

        long long new_damage = static_cast<long long>(d) + 20 * k + 100 + b;
        
        double increase_percent_double = (static_cast<double>(new_damage - d) * 100.0) / d;
        int increase_percent_int = static_cast<int>(ceil(increase_percent_double));

        std::cout << "ELEMENTO #" << i << "\n";
        std::cout << "DANO: " << new_damage << "\n";
        std::cout << "AUMENTO: " << increase_percent_int << "%\n";
        std::cout << "\n";
        
        if (new_damage > best_damage) {
            best_damage = new_damage;
            best_element_num = i;
            best_increase_percent = increase_percent_int;
        }
    }

    std::cout << "ELEMENTO ESCOLHIDO: #" << best_element_num << "\n";
    std::cout << "NOVO DANO DA ESPADA: " << best_damage << "\n";
    std::cout << "AUMENTO: " << best_increase_percent << "%\n";

    return 0;
}
