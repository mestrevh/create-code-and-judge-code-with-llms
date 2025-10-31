/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> board(n, std::vector<int>(n));
    int actual_ships = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> board[i][j];
            if (board[i][j] == 1) {
                actual_ships++;
            }
        }
    }

    if (actual_ships > k) {
        std::cout << "Defesa invalida!\n";
        return 0;
    }

    std::vector<std::pair<int, int>> attacks(2 * k);
    bool invalid_attack = false;
    for (int i = 0; i < 2 * k; ++i) {
        std::cin >> attacks[i].first >> attacks[i].second;
        if (attacks[i].first < 0 || attacks[i].first >= n || attacks[i].second < 0 || attacks[i].second >= n) {
            invalid_attack = true;
        }
    }

    if (invalid_attack) {
        std::cout << "Ataque invalido!\n";
        return 0;
    }

    int hits = 0;
    for (const auto& attack : attacks) {
        int r = attack.first;
        int c = attack.second;
        if (board[r][c] == 1) {
            hits++;
            board[r][c] = 0; 
        }
    }

    if (hits == actual_ships) {
        std::cout << "Ataque venceu!\n";
    } else {
        std::cout << "Defesa venceu!\n";
    }

    return 0;
}
