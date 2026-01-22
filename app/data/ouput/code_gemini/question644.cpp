/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, J;
    while (std::cin >> N >> J && (N != 0 || J != 0)) {
        std::queue<int> purchase_pile;
        for (int i = 0; i < N; ++i) {
            int card;
            std::cin >> card;
            purchase_pile.push(card);
        }

        std::vector<std::list<int>> player_piles(J + 1);
        std::vector<int> discard_area;
        int current_player = 1;

        while (!purchase_pile.empty()) {
            bool turn_continues = true;
            int turn_owner = current_player;

            while (turn_continues && !purchase_pile.empty()) {
                int card_of_the_turn = purchase_pile.front();
                purchase_pile.pop();

                bool match_found = false;

                auto it = std::find(discard_area.begin(), discard_area.end(), card_of_the_turn);
                if (it != discard_area.end()) {
                    int matched_card = *it;
                    discard_area.erase(it);
                    player_piles[turn_owner].push_back(matched_card);
                    player_piles[turn_owner].push_back(card_of_the_turn);
                    match_found = true;
                }

                if (!match_found) {
                    for (int other_player = 1; other_player <= J; ++other_player) {
                        if (other_player == turn_owner) continue;
                        if (!player_piles[other_player].empty() && player_piles[other_player].back() == card_of_the_turn) {
                            player_piles[turn_owner].splice(player_piles[turn_owner].end(), player_piles[other_player]);
                            player_piles[turn_owner].push_back(card_of_the_turn);
                            match_found = true;
                            break;
                        }
                    }
                }

                if (!match_found) {
                    if (!player_piles[turn_owner].empty() && player_piles[turn_owner].back() == card_of_the_turn) {
                        player_piles[turn_owner].push_back(card_of_the_turn);
                        match_found = true;
                    }
                }

                if (!match_found) {
                    discard_area.push_back(card_of_the_turn);
                    turn_continues = false;
                }
            }

            current_player++;
            if (current_player > J) {
                current_player = 1;
            }
        }

        int max_size = 0;
        for (int i = 1; i <= J; ++i) {
            if ((int)player_piles[i].size() > max_size) {
                max_size = player_piles[i].size();
            }
        }

        std::vector<int> winners;
        for (int i = 1; i <= J; ++i) {
            if ((int)player_piles[i].size() == max_size) {
                winners.push_back(i);
            }
        }

        std::cout << max_size;
        for (int winner : winners) {
            std::cout << " " << winner;
        }
        std::cout << "\n";
    }

    return 0;
}
