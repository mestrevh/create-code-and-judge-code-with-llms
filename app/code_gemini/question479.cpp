/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> map(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> map[i][j];
        }
    }

    int c;
    std::cin >> c;

    int currentX, currentY;
    std::cin >> currentX >> currentY;

    for (int i = 0; i < c; ++i) {
        char command;
        std::cin >> command;

        int nextX = currentX;
        int nextY = currentY;

        if (command == 'D') {
            nextY++;
        } else if (command == 'E') {
            nextY--;
        } else if (command == 'C') {
            nextX--;
        } else if (command == 'B') {
            nextX++;
        }

        if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
            if (map[nextX][nextY] == 1) {
                currentX = nextX;
                currentY = nextY;
            }
        }
    }

    std::cout << "(" << currentX << "," << currentY << ")" << std::endl;

    return 0;
}
