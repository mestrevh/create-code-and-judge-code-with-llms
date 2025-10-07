/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

void print_matrix(const std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            std::cout << matrix[i][j] << (j == 5 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    char focus;
    std::cin >> focus;

    int best_score = -1;
    std::string best_formation_string;
    std::vector<std::vector<int>> best_matrix(4, std::vector<int>(6));

    for (int i = 0; i < n; ++i) {
        std::vector<std::vector<int>> current_matrix(4, std::vector<int>(6));
        std::vector<int> counts(4, 0);
        std::vector<int> non_zero_indices;

        for (int r = 0; r < 4; ++r) {
            for (int c = 0; c < 6; ++c) {
                std::cin >> current_matrix[r][c];
                if (current_matrix[r][c] == 1) {
                    counts[r]++;
                }
            }
            if (counts[r] > 0) {
                non_zero_indices.push_back(r);
            }
        }
        
        int current_attack = 0;
        int current_mid = 0;
        int current_defense = 0;
        std::string current_formation_string;
        
        if (non_zero_indices.size() == 3) {
            current_defense = counts[non_zero_indices[2]];
            current_mid = counts[non_zero_indices[1]];
            current_attack = counts[non_zero_indices[0]];
            current_formation_string = std::to_string(current_defense) + "-" + 
                                     std::to_string(current_mid) + "-" + 
                                     std::to_string(current_attack);
        } else {
            current_defense = counts[3];
            current_mid = counts[1] + counts[2]; 
            current_attack = counts[0];
            current_formation_string = std::to_string(counts[3]) + "-" + 
                                     std::to_string(counts[2]) + "-" + 
                                     std::to_string(counts[1]) + "-" + 
                                     std::to_string(counts[0]);
        }

        int current_focus_score = 0;
        if (focus == 'D') {
            current_focus_score = current_defense;
        } else if (focus == 'M') {
            current_focus_score = current_mid;
        } else if (focus == 'A') {
            current_focus_score = current_attack;
        }

        if (current_focus_score > best_score) {
            best_score = current_focus_score;
            best_formation_string = current_formation_string;
            best_matrix = current_matrix;
        }
    }
    
    std::cout << "Pipi e Mariozito deviam escolher a formacao " << best_formation_string << std::endl;
    print_matrix(best_matrix);

    return 0;
}
