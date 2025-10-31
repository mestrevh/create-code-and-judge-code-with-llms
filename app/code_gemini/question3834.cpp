/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::vector<int>> grid(4, std::vector<int>(4, 0));
    int r = 0;
    int c = 0;

    grid[r][c]++;

    char move;
    for (int i = 0; i < 20; ++i) {
        std::cin >> move;
        if (move == 'c') {
            r--;
        } else if (move == 'b') {
            r++;
        } else if (move == 'e') {
            c--;
        } else if (move == 'd') {
            c++;
        }
        grid[r][c]++;
    }

    int unvisited_count = 0;
    int min_visits = 22;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] == 0) {
                unvisited_count++;
            } else {
                if (grid[i][j] < min_visits) {
                    min_visits = grid[i][j];
                }
            }
        }
    }

    std::cout << "Coordenada X:" << unvisited_count << ", Y:" << min_visits << std::endl;

    return 0;
}
