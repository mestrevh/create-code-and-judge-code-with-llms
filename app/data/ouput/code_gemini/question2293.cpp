/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int Q, X, C, N, M;
    std::cin >> Q >> X >> C >> N >> M;

    std::vector<std::string> names;
    names.push_back("YUKI");

    for (int i = 0; i < C; ++i) {
        std::string friend_name;
        std::cin >> friend_name;
        std::transform(friend_name.begin(), friend_name.end(), friend_name.begin(),
                   [](unsigned char c){ return std::toupper(c); });
        names.push_back(friend_name);
    }

    int kept_grids = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int q = 0; q < Q; ++q) {
        std::vector<std::string> grid(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> grid[i];
            std::transform(grid[i].begin(), grid[i].end(), grid[i].begin(),
                   [](unsigned char c){ return std::toupper(c); });
        }

        int current_occurrences = 0;

        for (const std::string& name : names) {
            int len = name.length();
            if (len < 1) continue;

            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < M; ++c) {
                    for (int d = 0; d < 4; ++d) {
                        bool match = true;
                        for (int k = 0; k < len; ++k) {
                            int nr = r + k * dr[d];
                            int nc = c + k * dc[d];

                            if (nr < 0 || nr >= N || nc < 0 || nc >= M || grid[nr][nc] != name[k]) {
                                match = false;
                                break;
                            }
                        }
                        if (match) {
                            current_occurrences++;
                        }
                    }
                }
            }
        }

        if (current_occurrences <= X) {
            kept_grids++;
        }
    }

    std::cout << kept_grids << std::endl;

    return 0;
}
