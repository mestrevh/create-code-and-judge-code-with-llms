/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

struct Player {
    std::string name;
    std::string country;
    int attack;
    int defense;
    int cost;
};

struct Club {
    std::string name;
    int money;
    char focus;
    std::vector<Player> bought_players;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n_clubs;
    std::cin >> n_clubs;

    std::vector<Club> clubs;
    for (int i = 0; i < n_clubs; ++i) {
        std::string club_name;
        int money;
        char focus;
        std::cin >> club_name;

        if (club_name == "Vasco") {
            std::cin >> money >> focus;
            std::cout << "Vasco nao tem salvacao, tomou 3 pro vitoria em casa\n";
        } else {
            std::cin >> money >> focus;
            clubs.push_back({club_name, money, focus, {}});
        }
    }

    int n_players;
    std::cin >> n_players;

    for (int i = 0; i < n_players; ++i) {
        Player current_player;
        std::cin >> current_player.name >> current_player.country >> current_player.attack >> current_player.defense >> current_player.cost;

        int best_club_idx = -1;

        for (int j = 0; j < clubs.size(); ++j) {
            if (clubs[j].money >= current_player.cost) {
                if (best_club_idx == -1) {
                    best_club_idx = j;
                } else {
                    Club& challenger = clubs[j];
                    Club& current_best = clubs[best_club_idx];
                    char player_type = (current_player.attack >= current_player.defense) ? 'A' : 'D';

                    bool challenger_has_priority = (challenger.focus == player_type);
                    bool current_best_has_priority = (current_best.focus == player_type);

                    if (challenger_has_priority && !current_best_has_priority) {
                        best_club_idx = j;
                    } else if (!challenger_has_priority && current_best_has_priority) {
                        // Current best is better, do nothing.
                    } else {
                        // Same focus priority, check money.
                        if (challenger.money > current_best.money) {
                            best_club_idx = j;
                        }
                        // If money is equal or less, the first offer (current_best) wins.
                    }
                }
            }
        }

        if (best_club_idx != -1) {
            std::cout << current_player.name << " eh do " << clubs[best_club_idx].name << "\n";
            clubs[best_club_idx].money -= current_player.cost;
            clubs[best_club_idx].bought_players.push_back(current_player);
        } else {
            std::cout << current_player.name << " ta muito caro\n";
        }
    }

    for (int i = 0; i < clubs.size(); ++i) {
        if (i > 0) {
            std::cout << "\n";
        }
        std::cout << "Situacao " << clubs[i].name << "\n";
        std::cout << "Dinheiro restante = " << clubs[i].money << "\n";
        std::cout << "Num de Jogadores = " << clubs[i].bought_players.size() << "\n";
        for (const auto& player : clubs[i].bought_players) {
            std::cout << player.name << " " << player.country << "\n";
        }
    }

    return 0;
}
