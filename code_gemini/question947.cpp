/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>

using State = std::vector<std::pair<char, int>>;
std::map<State, int> memo;

int solve(State groups) {
    if (groups.empty()) {
        return 1;
    }

    if (memo.count(groups)) {
        return memo[groups];
    }

    for (size_t i = 0; i < groups.size(); ++i) {
        if (groups[i].second >= 2) {
            State next_groups = groups;
            next_groups.erase(next_groups.begin() + i);

            if (i > 0 && i < next_groups.size()) {
                if (next_groups[i - 1].first == next_groups[i].first) {
                    next_groups[i - 1].second += next_groups[i].second;
                    next_groups.erase(next_groups.begin() + i);
                }
            }
            
            if (solve(next_groups) == 1) {
                return memo[groups] = 1;
            }
        }
    }
    
    return memo[groups] = 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        std::string s;
        std::cin >> s;
        
        memo.clear();
        
        if (s.empty()) {
            std::cout << 1 << "\n";
            continue;
        }

        State initial_groups;
        initial_groups.push_back({s[0], 1});
        for (size_t i = 1; i < s.length(); ++i) {
            if (s[i] == initial_groups.back().first) {
                initial_groups.back().second++;
            } else {
                initial_groups.push_back({s[i], 1});
            }
        }
        
        std::cout << solve(initial_groups) << "\n";
    }
    return 0;
}
