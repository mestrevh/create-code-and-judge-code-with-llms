/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

void printMap(const std::vector<std::vector<std::string>>& map) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << map[i][j] << (j == 4 ? "" : " ");
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int hp;
    std::cin >> hp;

    std::vector<std::vector<std::string>> map(5, std::vector<std::string>(5));
    int player_r = -1, player_c = -1;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cin >> map[i][j];
            if (map[i][j] == "@") {
                player_r = i;
                player_c = j;
            }
        }
    }

    int num_directions;
    std::cin >> num_directions;

    std::vector<char> directions(num_directions);
    for (int i = 0; i < num_directions; ++i) {
        std::cin >> directions[i];
    }

    bool alive = true;
    bool found_treasure = false;

    for (char move : directions) {
        if (!alive || found_treasure) {
            break;
        }

        int next_r = player_r;
        int next_c = player_c;

        if (move == 'C') {
            next_r--;
        } else if (move == 'D') {
            next_c++;
        } else if (move == 'E') {
            next_c--;
        }

        if (next_r < 0 || next_r >= 5 || next_c < 0 || next_c >= 5) {
            continue; 
        }

        std::string& target_cell = map[next_r][next_c];

        if (target_cell == "#") {
            std::cout << "Uma magic wall aqui? druid desgraçado\n";
        } else if (target_cell == "$") {
            found_treasure = true;
            map[player_r][player_c] = "*";
            map[next_r][next_c] = "@";
            player_r = next_r;
            player_c = next_c;
            break;
        } else { // It's a dragon
            int dragon_strength = std::stoi(target_cell);
            if (hp > dragon_strength) {
                hp -= dragon_strength;
                std::cout << "Minha Royal Spear deita qualquer Dragon\n";
                map[player_r][player_c] = "*";
                map[next_r][next_c] = "@";
                player_r = next_r;
                player_c = next_c;
            } else {
                alive = false;
                std::cout << "Minhas HPs acabaram, esse Frost Dragon me deitou\n";
                break;
            }
        }
    }

    printMap(map);

    if (found_treasure) {
        std::cout << "Finalmente acabei a quest\n";
    } else {
        std::cout << "Quem foi o newba que escreveu essas coordenadas\n";
    }

    return 0;
}
