/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

void solve(int r, int c, int current_captures, int& max_captures_for_start, int N, int M, int board[21][21]) {
    max_captures_for_start = std::max(max_captures_for_start, current_captures);

    int dr[] = {-1, -1, 1, 1};
    int dc[] = {-1, 1, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int r_opp = r + dr[i];
        int c_opp = c + dc[i];
        int r_land = r + 2 * dr[i];
        int c_land = c + 2 * dc[i];

        if (r_land >= 0 && r_land < N && c_land >= 0 && c_land < M &&
            board[r_opp][c_opp] == 2 &&
            board[r_land][c_land] == 0) {
            
            board[r][c] = 0;
            board[r_opp][c_opp] = 0;
            board[r_land][c_land] = 1;

            solve(r_land, c_land, current_captures + 1, max_captures_for_start, N, M, board);

            board[r][c] = 1;
            board[r_opp][c_opp] = 2;
            board[r_land][c_land] = 0;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    while (std::cin >> N >> M && (N != 0 || M != 0)) {
        int initial_board[21][21];
        std::vector<std::pair<int, int>> my_pieces;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if ((i + j) % 2 == 0) {
                    int val;
                    std::cin >> val;
                    initial_board[i][j] = val;
                    if (val == 1) {
                        my_pieces.push_back({i, j});
                    }
                } else {
                    initial_board[i][j] = -1;
                }
            }
        }

        int overall_max_captures = 0;
        
        for (const auto& p : my_pieces) {
            int board_copy[21][21];
            memcpy(board_copy, initial_board, sizeof(board_copy));
            
            int max_for_this_piece = 0;
            solve(p.first, p.second, 0, max_for_this_piece, N, M, board_copy);
            overall_max_captures = std::max(overall_max_captures, max_for_this_piece);
        }

        std::cout << overall_max_captures << std::endl;
    }

    return 0;
}
