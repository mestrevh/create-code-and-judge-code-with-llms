/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int grid[10][10];
bool visited[10][10];

bool findPath(int row, int col) {
    if (row < 0 || row >= 10 || col < 0 || col >= 10) {
        return false;
    }

    if (grid[row][col] == 0 || visited[row][col]) {
        return false;
    }

    visited[row][col] = true;

    if (row == 9 || col == 9) {
        return true;
    }

    if (findPath(row + 1, col)) {
        return true;
    }
    if (findPath(row, col + 1)) {
        return true;
    }
    if (findPath(row - 1, col)) {
        return true;
    }
    if (findPath(row, col - 1)) {
        return true;
    }

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    if (findPath(0, 0)) {
        std::cout << "RUN!\n";
    } else {
        std::cout << "Welcome to the Upside Down.\n";
    }

    return 0;
}
