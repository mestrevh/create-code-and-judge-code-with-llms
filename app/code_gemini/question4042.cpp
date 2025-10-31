/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string dims;
    std::cin >> dims;
    size_t x_pos = dims.find('x');
    int rows = std::stoi(dims.substr(0, x_pos));
    int cols = std::stoi(dims.substr(x_pos + 1));

    std::vector<std::string> grid(rows);
    int start_r = -1, start_c = -1, dest_r = -1, dest_c = -1;

    for (int i = 0; i < rows; ++i) {
        std::cin >> grid[i];
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 'o') {
                start_r = i;
                start_c = j;
            } else if (grid[i][j] == 'd') {
                dest_r = i;
                dest_c = j;
            }
        }
    }

    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> dist(rows, std::vector<int>(cols, -1));

    if (start_r != -1) {
        q.push({start_r, start_c});
        dist[start_r][start_c] = 0;
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        std::pair<int, int> current = q.front();
        q.pop();
        int r = current.first;
        int c = current.second;

        if (r == dest_r && c == dest_c) {
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] != '#' && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    if (dest_r != -1 && dist[dest_r][dest_c] != -1) {
        std::cout << "Apos correr " << dist[dest_r][dest_c] << " metros e quase desistir por causa da distância, Rebeka conseguiu escapar!\n";
    } else {
        std::cout << "Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir\n";
    }

    return 0;
}
