/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits>

void find_winner_recursive(int n_remaining, double current_patience, double& max_score, std::string& winner_name) {
    if (n_remaining == 0) {
        return;
    }

    std::string current_name;
    std::getline(std::cin, current_name);

    long long ascii_sum = 0;
    for (char c : current_name) {
        ascii_sum += static_cast<int>(c);
    }

    double current_score = ascii_sum * current_patience;

    if (current_name == "Troy Bolton" || current_name == "Gabriella Montez" ||
        current_name == "Sharpay Evans" || current_name == "Ryan Evans") {
        current_score += 350;
    }

    if (current_score > max_score) {
        max_score = current_score;
        winner_name = current_name;
    }

    find_winner_recursive(n_remaining - 1, current_patience * 0.99, max_score, winner_name);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double initial_patience;
    std::cin >> initial_patience;

    int n_candidates;
    std::cin >> n_candidates;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    double max_score = -1.0;
    std::string winner_name = "";

    find_winner_recursive(n_candidates, initial_patience, max_score, winner_name);

    std::cout << "O grande vencedor(a) do papel principal desse ano foi " << winner_name << "!" << std::endl;

    return 0;
}
