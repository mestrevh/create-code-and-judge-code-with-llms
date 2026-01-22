/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> board(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> board[i];
    }

    std::vector<std::vector<int>> ship_id(N, std::vector<int>(M, 0));
    std::vector<int> ship_size;
    ship_size.push_back(0); 

    int current_ship_id = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == '#' && ship_id[i][j] == 0) {
                current_ship_id++;
                int current_ship_size = 0;
                std::queue<std::pair<int, int>> q;

                q.push({i, j});
                ship_id[i][j] = current_ship_id;
                current_ship_size++;

                while (!q.empty()) {
                    std::pair<int, int> curr = q.front();
                    q.pop();

                    for (int k = 0; k < 4; ++k) {
                        int ni = curr.first + dr[k];
                        int nj = curr.second + dc[k];

                        if (ni >= 0 && ni < N && nj >= 0 && nj < M && board[ni][nj] == '#' && ship_id[ni][nj] == 0) {
                            ship_id[ni][nj] = current_ship_id;
                            current_ship_size++;
                            q.push({ni, nj});
                        }
                    }
                }
                ship_size.push_back(current_ship_size);
            }
        }
    }

    int K;
    std::cin >> K;

    std::vector<int> ship_hits(current_ship_id + 1, 0);

    for (int i = 0; i < K; ++i) {
        int r, c;
        std::cin >> r >> c;
        r--; 
        c--;

        if (ship_id[r][c] != 0) {
            ship_hits[ship_id[r][c]]++;
        }
    }

    int destroyed_ships = 0;
    for (int i = 1; i <= current_ship_id; ++i) {
        if (ship_hits[i] == ship_size[i]) {
            destroyed_ships++;
        }
    }

    std::cout << destroyed_ships << std::endl;

    return 0;
}
