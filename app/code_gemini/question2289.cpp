/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int N_maze, M_maze;
std::vector<std::vector<int>> grid;
std::vector<std::vector<bool>> visited;

bool findPath(int r, int c, std::vector<std::string>& path) {
    if (r < 0 || r >= N_maze || c < 0 || c >= M_maze || grid[r][c] == 0 || visited[r][c]) {
        return false;
    }

    visited[r][c] = true;

    if (r == N_maze - 1 && c == M_maze - 1) {
        return true;
    }

    path.push_back("Sul");
    if (findPath(r + 1, c, path)) {
        return true;
    }
    path.pop_back();

    path.push_back("Leste");
    if (findPath(r, c + 1, path)) {
        return true;
    }
    path.pop_back();

    path.push_back("Norte");
    if (findPath(r - 1, c, path)) {
        return true;
    }
    path.pop_back();

    path.push_back("Oeste");
    if (findPath(r, c - 1, path)) {
        return true;
    }
    path.pop_back();

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n_refens;
    std::cin >> n_refens;

    std::vector<int> counts(n_refens + 1, 0);
    for (int i = 0; i < n_refens; ++i) {
        int x;
        std::cin >> x;
        if (x >= 0 && x <= n_refens) {
            counts[x]++;
        }
    }

    bool truth_possible = false;
    for (int k = 1; k <= n_refens; ++k) {
        if (counts[k] == k) {
            truth_possible = true;
            break;
        }
    }

    if (!truth_possible) {
        std::cout << "Ja nao se pode confiar nos refens como antigamente...\n";
        return 0;
    }

    std::cout << "Vamo nessa, temos que sair rapido...\n";

    std::cin >> N_maze >> M_maze;

    grid.assign(N_maze, std::vector<int>(M_maze));
    visited.assign(N_maze, std::vector<bool>(M_maze, false));

    for (int i = 0; i < N_maze; ++i) {
        for (int j = 0; j < M_maze; ++j) {
            std::cin >> grid[i][j];
        }
    }

    std::vector<std::string> path;

    if (grid[0][0] == 0 || grid[N_maze - 1][M_maze - 1] == 0) {
        std::cout << "Continuem cavando!\n";
        return 0;
    }

    if (findPath(0, 0, path)) {
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i] << (i == path.size() - 1 ? "" : ",");
        }
        std::cout << "\n";
    } else {
        std::cout << "Continuem cavando!\n";
    }

    return 0;
}
