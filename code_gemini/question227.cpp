/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>

bool match(const std::string& card1, const std::string& card2) {
    return card1[0] == card2[0] || card1[1] == card2[1];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    while (std::getline(std::cin, line) && line[0] != '#') {
        std::string line2;
        std::getline(std::cin, line2);

        std::string full_deck_str = line + " " + line2;
        std::vector<std::string> cards;
        std::stringstream ss(full_deck_str);
        std::string card;
        while (ss >> card) {
            cards.push_back(card);
        }

        std::vector<std::vector<std::string>> piles;
        for (const auto& c : cards) {
            piles.push_back({c});
        }

        while (true) {
            bool move_made = false;
            size_t from_idx = 0;
            int to_idx = -1;

            for (size_t i = 1; i < piles.size(); ++i) {
                if (i >= 3 && match(piles[i].back(), piles[i - 3].back())) {
                    from_idx = i;
                    to_idx = i - 3;
                    move_made = true;
                    break;
                }
                if (match(piles[i].back(), piles[i - 1].back())) {
                    from_idx = i;
                    to_idx = i - 1;
                    move_made = true;
                    break;
                }
            }

            if (move_made) {
                piles[to_idx].insert(piles[to_idx].end(), piles[from_idx].begin(), piles[from_idx].end());
                piles.erase(piles.begin() + from_idx);
            } else {
                break;
            }
        }

        std::cout << piles.size() << " pilha" << (piles.size() != 1 ? "s" : "") << " sobrando:";
        for (const auto& p : piles) {
            std::cout << " " << p.size();
        }
        std::cout << std::endl;
    }

    return 0;
}
