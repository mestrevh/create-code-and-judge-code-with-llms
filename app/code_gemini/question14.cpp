/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int W, H, N;
    while (std::cin >> W >> H >> N && (W != 0 || H != 0 || N != 0)) {
        std::vector<std::vector<bool>> board(W + 1, std::vector<bool>(H + 1, false));

        for (int i = 0; i < N; ++i) {
            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;

            int start_x = std::min(x1, x2);
            int end_x = std::max(x1, x2);
            int start_y = std::min(y1, y2);
            int end_y = std::max(y1, y2);

            for (int x = start_x; x <= end_x; ++x) {
                for (int y = start_y; y <= end_y; ++y) {
                    board[x][y] = true;
                }
            }
        }

        int empty_spots = 0;
        for (int x = 1; x <= W; ++x) {
            for (int y = 1; y <= H; ++y) {
                if (!board[x][y]) {
                    empty_spots++;
                }
            }
        }

        if (empty_spots == 0) {
            std::cout << "There is no empty spots.\n";
        } else if (empty_spots == 1) {
            std::cout << "There is one empty spot.\n";
        } else {
            std::cout << "There are " << empty_spots << " empty spots.\n";
        }
    }

    return 0;
}
