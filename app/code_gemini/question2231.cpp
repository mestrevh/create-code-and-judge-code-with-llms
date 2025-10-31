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
    std::string hero;
    std::string flower;
    int bowser_health;

    std::cin >> hero >> flower >> bowser_health;

    int damage_per_hit = 0;

    if (hero == "Mario") {
        if (flower == "FireFlower") {
            damage_per_hit = 50;
        } else if (flower == "IceFlower") {
            damage_per_hit = 35;
        } else if (flower == "BoomerangFlower") {
            damage_per_hit = 30;
        }
    } else if (hero == "Luigi") {
        if (flower == "FireFlower") {
            damage_per_hit = 40;
        } else if (flower == "IceFlower") {
            damage_per_hit = 45;
        } else if (flower == "BoomerangFlower") {
            damage_per_hit = 25;
        }
    }

    int total_damage = damage_per_hit * 4;

    if (total_damage >= bowser_health) {
        std::cout << hero << " conseguiu derrotar o Bowser e salvar a princesa Peach.\n";
    } else {
        std::cout << "O Bowser conseguiu escapar.\n";
    }

    return 0;
}
