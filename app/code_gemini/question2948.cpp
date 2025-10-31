/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const int ROWS = 5;
    const int COLS = 10;

    char grid[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cin >> grid[i][j];
        }
    }

    double min_time = std::numeric_limits<double>::max();
    int best_x = -1;
    int best_y = -1;

    for (int y = 0; y < ROWS; ++y) {
        for (int x = 0; x < COLS; ++x) {
            char status = grid[y][x];

            if (status == '*') {
                continue;
            }

            double distance = std::sqrt(static_cast<double>(x * x + y * y));
            double current_time = distance * 20.0;

            if (status == '0') {
                current_time += 40.0;
            }

            if (current_time < min_time) {
                min_time = current_time;
                best_x = x;
                best_y = y;
            }
        }
    }

    if (best_x == -1) {
        std::cout << "Tristemente voce vai ter que aturar os PCs do grad 4\n";
    } else {
        std::cout << "Vai la pro computador " << best_x << " da fileira " << best_y << "\n";
    }

    return 0;
}
