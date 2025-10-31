/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <functional>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int S, L, C;
    while (std::cin >> S >> L >> C && (S != 0 || L != 0 || C != 0)) {
        std::vector<int> cell_costs;
        cell_costs.reserve(L * C);
        for (int r = 1; r <= L; ++r) {
            for (int c = 1; c <= C; ++c) {
                cell_costs.push_back(r + c);
            }
        }
        std::sort(cell_costs.begin(), cell_costs.end());

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for (int i = 0; i < S; ++i) {
            std::string sentence;
            std::getline(std::cin, sentence);

            std::map<char, int> char_freq;
            for (char ch : sentence) {
                if (ch != ' ') {
                    char_freq[ch]++;
                }
            }

            std::vector<int> freq_list;
            freq_list.reserve(char_freq.size());
            for (const auto& pair : char_freq) {
                freq_list.push_back(pair.second);
            }

            std::sort(freq_list.begin(), freq_list.end(), std::greater<int>());

            long long total_cost = 0;
            for (size_t j = 0; j < freq_list.size(); ++j) {
                total_cost += static_cast<long long>(freq_list[j]) * cell_costs[j];
            }
            std::cout << total_cost << "\n";
        }
    }

    return 0;
}
