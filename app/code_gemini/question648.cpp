/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, P;
    while (std::cin >> N >> P && (N != 0 || P != 0)) {
        std::vector<std::vector<int>> stacks(P);
        int pile_of_box1 = -1;
        int pos_in_pile = -1;
        for (int i = 0; i < P; ++i) {
            int q;
            std::cin >> q;
            stacks[i].resize(q);
            for (int j = 0; j < q; ++j) {
                std::cin >> stacks[i][j];
                if (stacks[i][j] == 1) {
                    pile_of_box1 = i;
                    pos_in_pile = j;
                }
            }
        }

        long long total_removed = 0;
        total_removed += (long long)(stacks[pile_of_box1].size() - 1 - pos_in_pile);
        
        long long target_height = pos_in_pile + 1;
        
        long long cost_left = -1;
        if (pile_of_box1 > 0) {
            cost_left = 0;
            long long right_wall_h = target_height;
            for (int i = pile_of_box1 - 1; i >= 0; --i) {
                long long current_h = stacks[i].size();
                if (current_h < right_wall_h) {
                    break;
                }
                cost_left += (current_h - right_wall_h + 1);
                right_wall_h = current_h + 1;
            }
        }

        long long cost_right = -1;
        if (pile_of_box1 < P - 1) {
            cost_right = 0;
            long long left_wall_h = target_height;
            for (int i = pile_of_box1 + 1; i < P; ++i) {
                long long current_h = stacks[i].size();
                if (current_h < left_wall_h) {
                    break;
                }
                cost_right += (current_h - left_wall_h + 1);
                left_wall_h = current_h + 1;
            }
        }

        long long additional_cost = 0;
        if (cost_left != -1 && cost_right != -1) {
            additional_cost = std::min(cost_left, cost_right);
        } else if (cost_left != -1) {
            additional_cost = cost_left;
        } else if (cost_right != -1) {
            additional_cost = cost_right;
        }

        total_removed += additional_cost;
        std::cout << total_removed << "\n";
    }
    return 0;
}
