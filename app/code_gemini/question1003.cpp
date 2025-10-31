/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    bool drawn[51] = {false};
    for (int i = 0; i < 10; ++i) {
        int num;
        std::cin >> num;
        if (num >= 1 && num <= 50) {
            drawn[num] = true;
        }
    }

    int n;
    std::cin >> n;

    std::map<int, std::vector<std::string>> results;

    for (int i = 0; i < n; ++i) {
        std::string code;
        std::cin >> code;

        int hits = 0;
        for (int j = 0; j < 15; ++j) {
            int bet_num;
            std::cin >> bet_num;
            if (bet_num >= 1 && bet_num <= 50 && drawn[bet_num]) {
                hits++;
            }
        }
        results[hits].push_back(code);
    }

    if (results.empty()) {
        return 0;
    }

    auto max_it = results.rbegin();
    int max_hits = max_it->first;
    const std::vector<std::string>& max_winners = max_it->second;

    std::cout << "Faixa: " << max_hits << " acertos\n";
    for (const auto& code : max_winners) {
        std::cout << code << "\n";
    }
    std::cout << max_winners.size() << (max_winners.size() > 1 ? " ganhadores" : " ganhador") << "\n";

    auto min_it = results.begin();
    int min_hits = min_it->first;

    if (min_hits != max_hits) {
        std::cout << "\n";
        const std::vector<std::string>& min_winners = min_it->second;
        
        std::cout << "Faixa: " << min_hits << " acertos\n";
        for (const auto& code : min_winners) {
            std::cout << code << "\n";
        }
        std::cout << min_winners.size() << (min_winners.size() > 1 ? " ganhadores" : " ganhador") << "\n";
    }

    return 0;
}
