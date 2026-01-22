/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string names[3] = {"Mario", "Yoshi", "Toad"};
    int total_distances[3];
    bool fell_in_hole[3] = {false, false, false};

    for (int i = 0; i < 3; ++i) {
        int current_dist_sum = 0;
        int consecutive_lefts = 0;
        
        for (int j = 0; j < 4; ++j) {
            std::string curve;
            int dist;
            std::cin >> curve >> dist;
            
            current_dist_sum += dist;
            
            if (curve == "Esquerda") {
                consecutive_lefts++;
            } else {
                consecutive_lefts = 0;
            }
            
            if (consecutive_lefts == 3) {
                fell_in_hole[i] = true;
            }
        }
        total_distances[i] = current_dist_sum;
    }

    for (int i = 0; i < 3; ++i) {
        if (fell_in_hole[i]) {
            std::cout << names[i] << " caiu em um buraco negro.\n";
        }
    }
    
    int min_dist = std::numeric_limits<int>::max();
    int winner_index = -1;

    for (int i = 0; i < 3; ++i) {
        if (!fell_in_hole[i]) {
            if (total_distances[i] < min_dist) {
                min_dist = total_distances[i];
                winner_index = i;
            }
        }
    }
    
    std::cout << names[winner_index] << " venceu a corrida!\n";

    return 0;
}
