/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::unordered_map<int, std::vector<int>> points_data;
    std::vector<std::set<std::pair<int, int>>> dominant_candidates(N);

    std::string command;
    int op_index = 0;

    while (std::cin >> command && command != "END") {
        if (command == "ADD") {
            int k;
            std::cin >> k;
            std::vector<int> V(N);
            for (int i = 0; i < N; ++i) {
                std::cin >> V[i];
            }

            points_data[k] = V;
            for (int j = 0; j < N; ++j) {
                dominant_candidates[j].insert({V[j], k});
            }

            int dominant_count = 0;
            for (int j = 0; j < N; ++j) {
                if (!dominant_candidates[j].empty()) {
                    if (dominant_candidates[j].rbegin()->second == k) {
                        dominant_count++;
                    }
                }
            }
            std::cout << op_index << " " << dominant_count << "\n";

        } else if (command == "UPD") {
            int k;
            std::cin >> k;
            std::vector<int> new_V(N);
            for (int i = 0; i < N; ++i) {
                std::cin >> new_V[i];
            }

            const std::vector<int>& old_V = points_data.at(k);
            for (int j = 0; j < N; ++j) {
                dominant_candidates[j].erase({old_V[j], k});
            }

            points_data[k] = new_V;
            for (int j = 0; j < N; ++j) {
                dominant_candidates[j].insert({new_V[j], k});
            }

            int dominant_count = 0;
            for (int j = 0; j < N; ++j) {
                 if (!dominant_candidates[j].empty()) {
                    if (dominant_candidates[j].rbegin()->second == k) {
                        dominant_count++;
                    }
                }
            }
            std::cout << op_index << " " << dominant_count << "\n";

        } else if (command == "MAX") {
            int j;
            std::cin >> j;

            auto dominant_pair = *dominant_candidates[j].rbegin();
            int dominant_key = dominant_pair.second;
            
            const std::vector<int>& V = points_data.at(dominant_key);

            std::cout << op_index << " " << dominant_key;
            for (int val : V) {
                std::cout << " " << val;
            }
            std::cout << "\n";
            
            for (int coord = 0; coord < N; ++coord) {
                dominant_candidates[coord].erase({V[coord], dominant_key});
            }
            points_data.erase(dominant_key);
        }
        op_index++;
    }

    return 0;
}
