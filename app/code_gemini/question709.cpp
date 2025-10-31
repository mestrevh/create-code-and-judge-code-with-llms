/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, o;
    std::cin >> n >> m >> o;

    std::vector<int> board(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> board[i];
    }

    std::vector<int> positions(m, 0);

    for (int i = 0; i < o; ++i) {
        for (int j = 0; j < m; ++j) {
            int dice_roll;
            std::cin >> dice_roll;

            int pos_after_dice = (positions[j] + dice_roll) % n;
            int board_move = board[pos_after_dice];
            
            positions[j] = ((pos_after_dice + board_move) % n + n) % n;
        }
    }

    for (int i = 0; i < m; ++i) {
        std::cout << positions[i] << '\n';
    }

    return 0;
}
