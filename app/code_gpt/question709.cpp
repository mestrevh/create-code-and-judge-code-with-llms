/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int n, m, o;
    std::cin >> n >> m >> o;
    std::vector<int> board(n);
    std::vector<int> positions(m, 0);

    for (int i = 0; i < n; ++i) {
        std::cin >> board[i];
    }

    for (int round = 0; round < o; ++round) {
        for (int player = 0; player < m; ++player) {
            int dice;
            std::cin >> dice;
            positions[player] = (positions[player] + dice) % n;
            if (positions[player] < 0) positions[player] += n;
            positions[player] = (positions[player] + board[positions[player]]) % n;
            if (positions[player] < 0) positions[player] += n;
        }
    }

    for (int pos : positions) {
        std::cout << pos << std::endl;
    }

    return 0;
}
