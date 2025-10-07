/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    long long total_extra_points = 0;
    std::vector<int> possible_cards = {1, 10, 100, 1000, 10000};

    for (int i = 0; i < m; ++i) {
        int budget;
        int daedalus_card;
        std::cin >> budget >> daedalus_card;

        int sum_others = 0;
        for (int j = 1; j < n; ++j) {
            int other_card;
            std::cin >> other_card;
            sum_others += other_card;
        }

        int points_actual = 0;
        if (daedalus_card + sum_others <= budget) {
            points_actual = daedalus_card;
        }

        int points_optimal = 0;
        for (int k = possible_cards.size() - 1; k >= 0; --k) {
            int card_choice = possible_cards[k];
            if (card_choice + sum_others <= budget) {
                points_optimal = card_choice;
                break;
            }
        }
        
        total_extra_points += (points_optimal - points_actual);
    }

    std::cout << total_extra_points << std::endl;

    return 0;
}
