/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

bool found = false;
bool discovered = false;
int found_corridor = -1;
int found_locker = -1;

void findTreasure(int current_corridor, int current_locker, int N, int Y, const std::vector<std::vector<int>>& grid) {
    if (found || discovered || current_locker >= Y) {
        return;
    }

    int value = grid[current_corridor][current_locker];

    if (value < 0) {
        discovered = true;
        return;
    }

    if (value == 0 && !found) {
        found = true;
        found_corridor = current_corridor + 1;
        found_locker = current_locker + 1;
        return;
    }

    int next_corridor = current_corridor + 1;
    int next_locker = current_locker;

    if (next_corridor >= N) {
        next_corridor = 0;
        next_locker = current_locker + 1;
    }

    findTreasure(next_corridor, next_locker, N, Y, grid);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, Y;
    std::cin >> N >> Y;

    if (N <= 0 || Y <= 0) {
        std::cout << "Sharpay endoidou!" << std::endl;
        return 0;
    }

    std::vector<std::vector<int>> grid(N, std::vector<int>(Y));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < Y; ++j) {
            std::cin >> grid[i][j];
        }
    }

    findTreasure(0, 0, N, Y, grid);

    if (discovered) {
        std::cout << "Voce foi descoberto! Corra dancando Bop To the Top!!" << std::endl;
    } else if (found) {
        std::cout << "O armario a ser invadido fica no corredor " << found_corridor
                  << ", e e o armario de numero " << found_locker << "." << std::endl;
    } else {
        std::cout << "Sharpay endoidou!" << std::endl;
    }

    return 0;
}
