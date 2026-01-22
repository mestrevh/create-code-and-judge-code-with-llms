/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> ninjas(8);
    for (int i = 0; i < 8; ++i) {
        std::getline(std::cin, ninjas[i]);
    }

    std::vector<std::pair<int, int>> quarter_matchups(4);
    for (int i = 0; i < 4; ++i) {
        std::cin >> quarter_matchups[i].first >> quarter_matchups[i].second;
    }

    std::cout << "Bem vindos ao Exame Chunnin!" << std::endl;
    for (int i = 0; i < 4; ++i) {
        int idx1 = quarter_matchups[i].first;
        int idx2 = quarter_matchups[i].second;
        std::cout << "Quartas de final " << i + 1 << ": " << ninjas[idx1] << " x " << ninjas[idx2] << std::endl;
    }

    std::vector<std::string> semi_finalists(4);
    for (int i = 0; i < 4; ++i) {
        std::string winner_code;
        std::cin >> winner_code;
        int idx1 = quarter_matchups[i].first;
        int idx2 = quarter_matchups[i].second;
        if (winner_code == "A") {
            semi_finalists[i] = ninjas[idx1];
        } else {
            semi_finalists[i] = ninjas[idx2];
        }
    }

    std::cout << "Semifinal 1: " << semi_finalists[0] << " x " << semi_finalists[1] << std::endl;
    std::cout << "Semifinal 2: " << semi_finalists[2] << " x " << semi_finalists[3] << std::endl;

    std::vector<std::string> finalists(2);
    std::string winner_code_s1;
    std::cin >> winner_code_s1;
    if (winner_code_s1 == "X") {
        finalists[0] = semi_finalists[0];
    } else {
        finalists[0] = semi_finalists[1];
    }

    std::string winner_code_s2;
    std::cin >> winner_code_s2;
    if (winner_code_s2 == "X") {
        finalists[1] = semi_finalists[2];
    } else {
        finalists[1] = semi_finalists[3];
    }

    std::cout << "Final: " << finalists[0] << " x " << finalists[1] << std::endl;

    std::string champion;
    std::string winner_code_f;
    std::cin >> winner_code_f;
    if (winner_code_f == "#") {
        champion = finalists[0];
    } else {
        champion = finalists[1];
    }

    std::cout << "O grande vencedor e " << champion << "!" << std::endl;

    return 0;
}
