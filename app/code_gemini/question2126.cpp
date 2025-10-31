/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

bool findPath(int mapa[10][10], int row, int col) {
    if (row < 0 || row >= 10 || col < 0 || col >= 10) {
        return false;
    }

    if (mapa[row][col] != 1) {
        return false;
    }

    if (row == 9 && col == 9) {
        return true;
    }

    mapa[row][col] = 2;

    if (findPath(mapa, row + 1, col)) {
        return true;
    }
    if (findPath(mapa, row, col + 1)) {
        return true;
    }
    if (findPath(mapa, row - 1, col)) {
        return true;
    }
    if (findPath(mapa, row, col - 1)) {
        return true;
    }

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int mapa[10][10];

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cin >> mapa[i][j];
        }
    }

    if (findPath(mapa, 0, 0)) {
        std::cout << "RUN!" << std::endl;
    } else {
        std::cout << "Welcome to the Upside Down." << std::endl;
    }

    return 0;
}
