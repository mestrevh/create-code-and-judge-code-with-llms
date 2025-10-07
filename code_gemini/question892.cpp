/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int H, C;
    std::cin >> H >> C;

    std::vector<std::string> grid(H);
    for (int i = 0; i < H; ++i) {
        std::cin >> grid[i];
    }

    bool possible = true;
    
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < C; ++c) {
            if (grid[r][c] == '*') {
                bool is_covered = false;
                for (int i = 0; i < 8; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < H && nc >= 0 && nc < C) {
                        if (grid[nr][nc] == '&') {
                            is_covered = true;
                            break;
                        }
                    }
                }
                if (!is_covered) {
                    possible = false;
                    break;
                }
            }
        }
        if (!possible) {
            break;
        }
    }

    if (possible) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }

    return 0;
}
