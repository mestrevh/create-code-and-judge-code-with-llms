/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c;
    int initial_energy;
    char weapon;

    std::cin >> a >> b >> c >> initial_energy;
    std::cin >> weapon;

    int enemies[3] = {a, b, c};

    int damage = 0;
    int base_cost = 0;

    if (weapon == 'C') {
        damage = 40;
        base_cost = 15;
    } else {
        damage = 50;
        base_cost = 20;
    }

    int current_energy = initial_energy;
    double threshold = initial_energy * 0.3;
    bool survived_all_fights = true;

    for (int i = 0; i < 3; ++i) {
        int current_enemy_hp = enemies[i];

        while (current_enemy_hp > 0) {
            if (current_energy <= 0) {
                survived_all_fights = false;
                break;
            }

            int attack_cost = base_cost;
            if (current_energy < threshold) {
                attack_cost *= 2;
            }

            current_energy -= attack_cost;
            current_enemy_hp -= damage;
        }

        if (!survived_all_fights) {
            break;
        }
    }

    if (survived_all_fights && current_energy > 0) {
        std::cout << "Eba! Pedro sobreviveu\n";
    } else {
        std::cout << "Que pena... Era um jovem tao promissor\n";
    }

    return 0;
}
