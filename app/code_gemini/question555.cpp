/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int line_width;
    std::cin >> line_width;
    std::cin.ignore();

    std::string line;
    std::getline(std::cin, line);

    std::vector<std::string> words;
    std::stringstream ss(line);
    std::string word;
    while (ss >> word) {
        words.push_back(word);
    }

    int n = words.size();
    if (n == 0) {
        return 0;
    }

    std::vector<long long> dp(n + 1, std::numeric_limits<long long>::max());
    std::vector<int> p(n, -1);

    dp[n] = 0;

    for (int i = n - 1; i >= 0; --i) {
        int current_word_lengths_sum = 0;
        for (int j = i; j < n; ++j) {
            current_word_lengths_sum += words[j].length();
            
            int current_total_length = current_word_lengths_sum + (j - i);

            if (current_total_length > line_width) {
                break;
            }

            long long spaces_for_cost = line_width - current_word_lengths_sum;
            long long line_cost = spaces_for_cost * spaces_for_cost * spaces_for_cost;

            if (dp[j + 1] != std::numeric_limits<long long>::max()) {
                long long total_cost = line_cost + dp[j + 1];
                if (total_cost < dp[i]) {
                    dp[i] = total_cost;
                    p[i] = j + 1;
                }
            }
        }
    }

    int current_word_index = 0;
    while (current_word_index < n) {
        int next_word_index = p[current_word_index];
        for (int k = current_word_index; k < next_word_index; ++k) {
            std::cout << words[k] << (k == next_word_index - 1 ? "" : " ");
        }
        std::cout << "\n";
        current_word_index = next_word_index;
    }

    return 0;
}
