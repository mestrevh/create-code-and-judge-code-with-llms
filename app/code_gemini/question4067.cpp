/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct Pokemon {
    std::string name;
    std::string type;
    int attack;
    int defense;
    double advantage_factor;
};

bool is_effective(const std::string& attacker_type, const std::string& defender_type) {
    if (attacker_type == "agua" && defender_type == "fogo") return true;
    if (attacker_type == "grama" && defender_type == "agua") return true;
    if (attacker_type == "fogo" && defender_type == "grama") return true;
    return false;
}

bool comparePokemon(const Pokemon& a, const Pokemon& b) {
    if (a.advantage_factor != b.advantage_factor) {
        return a.advantage_factor > b.advantage_factor;
    }
    return a.name < b.name;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Pokemon enemy;
    std::cin >> enemy.name >> enemy.type >> enemy.attack >> enemy.defense;

    int n;
    std::cin >> n;

    std::vector<Pokemon> ash_pokemon_list(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> ash_pokemon_list[i].name >> ash_pokemon_list[i].type >> ash_pokemon_list[i].attack >> ash_pokemon_list[i].defense;

        double effective_attack = ash_pokemon_list[i].attack;
        if (is_effective(ash_pokemon_list[i].type, enemy.type)) {
            effective_attack *= 1.5;
        }
        ash_pokemon_list[i].advantage_factor = effective_attack - enemy.defense;
    }

    std::sort(ash_pokemon_list.begin(), ash_pokemon_list.end(), comparePokemon);

    for (int i = 0; i < n; ++i) {
        std::cout << i + 1 << ". " << ash_pokemon_list[i].name << std::endl;
    }

    return 0;
}
