/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

void print_board(const std::vector<std::vector<int>>& board) {
    int N = board.size();
    int M = board[0].size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << " " << board[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int count_neighbors(const std::vector<std::vector<int>>& board, int r, int c) {
    int N = board.size();
    int M = board[0].size();
    int count = 0;
    
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) {
                continue;
            }
            int nr = r + dr;
            int nc = c + dc;
            if (nr >= 0 && nr < N && nc >= 0 && nc < M && board[nr][nc] == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M, V, G;
    std::cin >> N >> M >> V >> G;

    std::vector<std::vector<int>> current_board(N, std::vector<int>(M, 0));

    for (int i = 0; i < V; ++i) {
        int y, x;
        std::cin >> y >> x;
        current_board[y - 1][x - 1] = 1;
    }

    print_board(current_board);

    std::vector<std::vector<int>> next_board(N, std::vector<int>(M, 0));

    for (int gen = 0; gen < G; ++gen) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int neighbors = count_neighbors(current_board, i, j);
                
                if (current_board[i][j] == 1) { // Cell is alive
                    if (neighbors < 2 || neighbors > 3) {
                        next_board[i][j] = 0; // Dies
                    } else {
                        next_board[i][j] = 1; // Survives
                    }
                } else { // Cell is dead
                    if (neighbors == 3) {
                        next_board[i][j] = 1; // Becomes alive
                    } else {
                        next_board[i][j] = 0; // Stays dead
                    }
                }
            }
        }
        current_board = next_board;
        print_board(current_board);
    }

    return 0;
}
