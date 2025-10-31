/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

struct Clue {
    int x, y, d;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<Clue> clues(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> clues[i].x >> clues[i].y >> clues[i].d;
    }

    int found_count = 0;
    int treasure_x = -1;
    int treasure_y = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            
            bool is_possible_location = true;
            
            for (const auto& clue : clues) {
                int dist = std::abs(i - clue.x) + std::abs(j - clue.y);
                if (dist != clue.d) {
                    is_possible_location = false;
                    break;
                }
            }

            if (is_possible_location) {
                found_count++;
                treasure_x = i;
                treasure_y = j;
            }
        }
    }

    if (found_count == 1) {
        std::cout << treasure_x << " " << treasure_y << "\n";
    } else {
        std::cout << "-1 -1\n";
    }

    return 0;
}
