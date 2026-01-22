/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    bool holes[8][8] = {false};
    holes[1][3] = true;
    holes[2][3] = true;
    holes[2][5] = true;
    holes[5][4] = true;

    int dx[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {0, 2, 1, -1, -2, -2, -1, 1, 2};

    int current_x = 4;
    int current_y = 3;

    int n;
    std::cin >> n;

    int successful_moves = 0;
    for (int i = 0; i < n; ++i) {
        int move_type;
        std::cin >> move_type;

        int next_x = current_x + dx[move_type];
        int next_y = current_y + dy[move_type];

        successful_moves++;

        if (holes[next_x][next_y]) {
            break;
        }

        current_x = next_x;
        current_y = next_y;
    }

    std::cout << successful_moves << std::endl;

    return 0;
}
