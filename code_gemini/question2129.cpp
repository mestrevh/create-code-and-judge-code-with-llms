/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int M, N;
std::vector<std::vector<int>> grid;
std::vector<std::vector<bool>> visited;
std::vector<std::string> path;

bool solve(int r, int c) {
    if (r < 0 || r >= M || c < 0 || c >= N) {
        return false;
    }

    if (grid[r][c] == 0 || visited[r][c]) {
        return false;
    }

    if ((r != 0 || c != 0) && (r == 0 || r == M - 1 || c == 0 || c == N - 1)) {
        return true;
    }

    visited[r][c] = true;

    if (solve(r + 1, c)) {
        path.push_back("Sul");
        return true;
    }
    if (solve(r, c + 1)) {
        path.push_back("Leste");
        return true;
    }
    if (solve(r - 1, c)) {
        path.push_back("Norte");
        return true;
    }
    if (solve(r, c - 1)) {
        path.push_back("Oeste");
        return true;
    }

    visited[r][c] = false;

    return false;
}

void print_compressed_path() {
    if (path.empty()) {
        return;
    }

    std::reverse(path.begin(), path.end());

    bool first = true;
    for (size_t i = 0; i < path.size(); ) {
        std::string current_move = path[i];
        int count = 0;
        size_t j = i;
        while (j < path.size() && path[j] == current_move) {
            count++;
            j++;
        }

        if (!first) {
            std::cout << ", ";
        }
        first = false;

        if (count > 1) {
            std::cout << count << "*" << current_move;
        } else {
            std::cout << current_move;
        }

        i = j;
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> M >> N;

    grid.resize(M, std::vector<int>(N));
    visited.resize(M, std::vector<bool>(N, false));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> grid[i][j];
        }
    }

    if (solve(0, 0)) {
        print_compressed_path();
    } else {
        std::cout << "Welcome to the Upside Down." << std::endl;
    }

    return 0;
}
