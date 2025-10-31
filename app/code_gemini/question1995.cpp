/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>

struct Player {
    int life;
    std::map<char, int> creatures;

    Player() : life(0) {
        creatures['F'] = 0;
        creatures['G'] = 0;
        creatures['T'] = 0;
    }

    bool hasCreatures() const {
        return creatures.at('F') > 0 || creatures.at('G') > 0 || creatures.at('T') > 0;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Player players[2];
    std::cin >> players[0].life >> players[1].life;

    int current_player_idx = 0;

    std::string play_str;
    while (std::cin >> play_str) {
        char action = play_str[0];
        char type = play_str[1];
        int opponent_player_idx = 1 - current_player_idx;

        if (action == 'C') {
            players[current_player_idx].creatures[type]++;
        } else {
            int strength;
            std::cin >> strength;

            Player& opponent = players[opponent_player_idx];

            if (opponent.creatures[type] > 0) {
                opponent.creatures[type]--;
            } else if (opponent.hasCreatures()) {
                // Magic is absorbed
            } else {
                opponent.life -= strength;
            }
        }

        if (players[0].life <= 0 || players[1].life <= 0) {
            break;
        }

        current_player_idx = 1 - current_player_idx;
    }

    if (players[1].life <= 0) {
        std::cout << "O jogador 1 ganhou!" << std::endl;
    } else {
        std::cout << "O jogador 2 ganhou!" << std::endl;
    }

    return 0;
}
