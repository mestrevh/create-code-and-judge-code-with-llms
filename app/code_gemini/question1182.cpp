/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string pokemon_name;
    std::string attack_name;
    int moltres_level;

    std::cin >> pokemon_name >> attack_name >> moltres_level;

    double attacker_level;
    double attacker_attack;

    if (pokemon_name == "Slowbro") {
        attacker_level = 30;
        attacker_attack = 50;
    } else if (pokemon_name == "Dragonite") {
        attacker_level = 40;
        attacker_attack = 128;
    } else {
        std::cout << "Pokemon invalido\n";
        return 0;
    }

    double attack_power;
    double modifier;

    if (attack_name == "Surf") {
        attack_power = 90;
        modifier = 2.0;
    } else if (attack_name == "Flamethrower") {
        attack_power = 90;
        modifier = 0.5;
    } else if (attack_name == "Grass Knot") {
        attack_power = 120;
        modifier = 0.5;
    } else {
        std::cout << "Ataque invalido\n";
        return 0;
    }

    double moltres_hp = floor((169.0 * moltres_level) / 50.0 + 10.0);
    double moltres_defense = (229.0 * moltres_level) / 100.0 + 5.0;

    double damage_per_hit = floor(((((2.0 * attacker_level / 5.0 + 2.0) * attack_power * attacker_attack / moltres_defense) / 50.0 + 2.0) * modifier));

    double final_hp = moltres_hp - (4 * damage_per_hit);

    if (final_hp <= 0) {
        std::cout << "Moltres morto\n";
    } else if (final_hp < 10) {
        std::cout << "Moltres capturado\n";
    } else {
        std::cout << "Moltres fugiu\n";
    }

    return 0;
}
