/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    
    // Read the 10 sorted numbers
    std::vector<int> sorted_numbers(10);
    for (int i = 0; i < 10; ++i) {
        std::cin >> sorted_numbers[i];
    }

    int N;
    std::cin >> N;

    std::cin.ignore(); // Consume the rest of the line after reading N

    // Use a map to store winners by their score
    // Key: score, Value: vector of winner codes
    std::map<int, std::vector<std::string>> scores_to_winners;

    int max_score = 0;
    int min_score = 11; // Max possible score is 10, so 11 is a safe initial value

    for (int i = 0; i < N; ++i) {
        std::string code;
        std::cin >> code;

        int current_score = 0;
        for (int j = 0; j < 15; ++j) {
            int bet_number;
            std::cin >> bet_number;
            // Check if the bet number is in the sorted_numbers (draw)
            // Since sorted_numbers is sorted, we can use binary_search for O(log K) where K=10
            if (std::binary_search(sorted_numbers.begin(), sorted_numbers.end(), bet_number)) {
                current_score++;
            }
        }
        
        scores_to_winners[current_score].push_back(code);

        if (current_score > max_score) {
            max_score = current_score;
        }
        if (current_score < min_score) {
            min_score = current_score;
        }
    }

    // Output for max score winners
    std::cout << "Faixa: " << max_score << " acertos\n";
    for (const std::string& winner_code : scores_to_winners[max_score]) {
        std::cout << winner_code << "\n";
    }
    std::cout << scores_to_winners[max_score].size() << " ganhadores\n";

    // Output separator
    std::cout << "\n";

    // Output for min score winners, only if min_score is different from max_score
    if (min_score != max_score) {
        std::cout << "Faixa: " << min_score << " acertos\n";
        for (const std::string& winner_code : scores_to_winners[min_score]) {
            std::cout << winner_code << "\n";
        }
        std::cout << scores_to_winners[min_score].size() << " ganhadores\n";
    }

    return 0;
}