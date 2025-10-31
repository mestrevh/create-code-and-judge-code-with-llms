/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::vector<int>> database;
    std::vector<std::multiset<int>> blinks_per_minute(1140);

    int t;
    while (std::cin >> t && t != 0) {
        if (t == 1) {
            int Q;
            std::cin >> Q;
            std::vector<int> new_day_data(Q);
            for (int j = 0; j < Q; ++j) {
                std::cin >> new_day_data[j];
                blinks_per_minute[j].insert(new_day_data[j]);
            }
            database.push_back(std::move(new_day_data));
            std::cout << database.size() << "\n";
        } else if (t == 2) {
            int d;
            std::cin >> d;
            
            const std::vector<int>& day_to_delete = database[d];
            int minutes_removed = day_to_delete.size();

            for (int j = 0; j < minutes_removed; ++j) {
                auto it = blinks_per_minute[j].find(day_to_delete[j]);
                if (it != blinks_per_minute[j].end()) {
                    blinks_per_minute[j].erase(it);
                }
            }
            
            database.erase(database.begin() + d);
            
            std::cout << minutes_removed << "\n";
        } else if (t == 3) {
            int i;
            std::cin >> i;
            
            if (database[i].empty()) {
                std::cout << 0 << "\n";
            } else {
                std::cout << *std::max_element(database[i].begin(), database[i].end()) << "\n";
            }
        } else if (t == 4) {
            int j;
            std::cin >> j;
            
            if (blinks_per_minute[j].empty()) {
                std::cout << 0 << "\n";
            } else {
                std::cout << *blinks_per_minute[j].rbegin() << "\n";
            }
        }
    }

    return 0;
}
