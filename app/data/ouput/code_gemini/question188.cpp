/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <map>

struct Indian {
    int pos;
    int dir;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, e;
    std::cin >> n >> e;

    std::vector<Indian> indians(e);
    std::set<int> initial_positions;

    for (int i = 0; i < e; ++i) {
        std::cin >> indians[i].pos >> indians[i].dir;
        indians[i].pos--; 
        initial_positions.insert(indians[i].pos);
    }

    if (e == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int beats = 0;
    while (true) {
        beats++;

        std::vector<bool> will_move(e, true);
        std::vector<bool> to_reverse(e, false);
        std::vector<Indian> next_state = indians;

        std::vector<int> log_to_indian_idx(n, -1);
        for (int i = 0; i < e; ++i) {
            log_to_indian_idx[indians[i].pos] = i;
        }

        for (int i = 0; i < e; ++i) {
            if (indians[i].dir == 1) {
                int current_pos = indians[i].pos;
                int next_log = (current_pos + 1) % n;
                int other_idx = log_to_indian_idx[next_log];
                if (other_idx != -1 && indians[other_idx].dir == -1) {
                    will_move[i] = false;
                    will_move[other_idx] = false;
                    to_reverse[i] = !to_reverse[i];
                    to_reverse[other_idx] = !to_reverse[other_idx];
                }
            }
        }

        std::map<int, std::vector<int>> new_log_occupants;
        for (int i = 0; i < e; ++i) {
            if (will_move[i]) {
                next_state[i].pos = (indians[i].pos + indians[i].dir + n) % n;
            }
            new_log_occupants[next_state[i].pos].push_back(i);
        }

        for (auto const& [p, occupants] : new_log_occupants) {
            if (occupants.size() >= 2) {
                bool arrived_cw = false;
                bool arrived_ccw = false;
                for (int idx : occupants) {
                    if (will_move[idx]) {
                        if (indians[idx].dir == 1) {
                            arrived_cw = true;
                        } else {
                            arrived_ccw = true;
                        }
                    }
                }
                if (arrived_cw && arrived_ccw) {
                    for (int idx : occupants) {
                        to_reverse[idx] = !to_reverse[idx];
                    }
                }
            }
        }

        for (int i = 0; i < e; ++i) {
            if (to_reverse[i]) {
                next_state[i].dir *= -1;
            }
        }
        
        indians = next_state;

        std::set<int> current_positions;
        for (int i = 0; i < e; ++i) {
            current_positions.insert(indians[i].pos);
        }

        if (current_positions == initial_positions) {
            break;
        }
    }

    std::cout << beats << std::endl;

    return 0;
}
