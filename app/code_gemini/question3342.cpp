/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char teams[8];
    for (int i = 0; i < 8; ++i) {
        std::cin >> teams[i];
    }

    char qf_teams[4][2];
    for (int i = 0; i < 4; ++i) {
        int idx1, idx2;
        std::cin >> idx1 >> idx2;
        qf_teams[i][0] = teams[idx1];
        qf_teams[i][1] = teams[idx2];
        std::cout << "Quartas de final " << i + 1 << ": " << qf_teams[i][0] << " x " << qf_teams[i][1] << "\n";
    }

    char qf_winners[4];
    for (int i = 0; i < 4; ++i) {
        char winner_code;
        std::cin >> winner_code;
        if (winner_code == 'A') {
            qf_winners[i] = qf_teams[i][0];
        } else {
            qf_winners[i] = qf_teams[i][1];
        }
    }

    std::cout << "Semifinal 1: " << qf_winners[0] << " x " << qf_winners[1] << "\n";
    std::cout << "Semifinal 2: " << qf_winners[2] << " x " << qf_winners[3] << "\n";

    char sf_winners[2];
    char sf1_winner_code;
    std::cin >> sf1_winner_code;
    if (sf1_winner_code == 'X') {
        sf_winners[0] = qf_winners[0];
    } else {
        sf_winners[0] = qf_winners[1];
    }

    char sf2_winner_code;
    std::cin >> sf2_winner_code;
    if (sf2_winner_code == 'X') {
        sf_winners[1] = qf_winners[2];
    } else {
        sf_winners[1] = qf_winners[3];
    }

    std::cout << "Final: " << sf_winners[0] << " x " << sf_winners[1] << "\n";

    char champion;
    char final_winner_code;
    std::cin >> final_winner_code;
    if (final_winner_code == '#') {
        champion = sf_winners[0];
    } else {
        champion = sf_winners[1];
    }

    std::cout << "O vencedor da competição de futebol de robôs foi " << champion << "!\n";

    return 0;
}
