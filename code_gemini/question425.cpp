/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        std::vector<std::string> players(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> players[i];
        }

        std::vector<int> deck(52);
        for (int i = 0; i < 52; ++i) {
            std::cin >> deck[i];
        }

        std::vector<bool> is_active(n, true);
        int num_active = n;
        int deck_pos = 0;

        while (num_active > 1) {
            if (deck_pos + num_active > 52) {
                break;
            }

            std::vector<std::pair<int, int>> round_draws;
            int min_card = 14;

            for (int i = 0; i < n; ++i) {
                if (is_active[i]) {
                    int card = deck[deck_pos++];
                    round_draws.push_back({card, i});
                    if (card < min_card) {
                        min_card = card;
                    }
                }
            }

            int elim_count = 0;
            for (const auto& draw : round_draws) {
                if (draw.first == min_card) {
                    elim_count++;
                }
            }

            if (elim_count == num_active) {
                break;
            }

            for (const auto& draw : round_draws) {
                if (draw.first == min_card) {
                    if (is_active[draw.second]) {
                        is_active[draw.second] = false;
                        num_active--;
                    }
                }
            }
        }

        bool first_winner = true;
        for (int i = 0; i < n; ++i) {
            if (is_active[i]) {
                if (!first_winner) {
                    std::cout << " ";
                }
                std::cout << players[i];
                first_winner = false;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
