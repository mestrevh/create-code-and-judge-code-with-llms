/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n, std::string(m, ' '));
    int snake_r = -1, snake_c = -1;
    int total_fruits = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char cell;
            std::cin >> cell;
            grid[i][j] = cell;
            if (cell == '#') {
                snake_r = i;
                snake_c = j;
            } else if (cell == 'O') {
                total_fruits++;
            }
        }
    }

    int game_mode;
    std::cin >> game_mode;

    std::string commands;
    std::cin >> commands;

    int fruits_eaten = 0;
    bool game_over = false;
    bool won = false;

    for (char cmd : commands) {
        int prev_r = snake_r;
        int prev_c = snake_c;

        int next_r = snake_r;
        int next_c = snake_c;

        if (cmd == 'N') {
            next_r--;
        } else if (cmd == 'S') {
            next_r++;
        } else if (cmd == 'O') {
            next_c--;
        } else if (cmd == 'L') {
            next_c++;
        }
        
        if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) {
            if (game_mode == 1) {
                game_over = true;
                break;
            } else { 
                if (next_r < 0) next_r = n - 1;
                else if (next_r >= n) next_r = 0;
                
                if (next_c < 0) next_c = m - 1;
                else if (next_c >= m) next_c = 0;
            }
        }

        char next_cell = grid[next_r][next_c];
        if (next_cell == '%') {
            game_over = true;
            break;
        }

        if (next_cell == 'O') {
            fruits_eaten++;
        }

        grid[prev_r][prev_c] = '.';
        snake_r = next_r;
        snake_c = next_c;
        grid[snake_r][snake_c] = '#';

        if (total_fruits > 0 && fruits_eaten == total_fruits) {
            won = true;
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << grid[i][j] << (j == m - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    if (game_over) {
        std::cout << " - GAME OVER - " << std::endl;
    } else if (won) {
        std::cout << "Parabens, voce venceu!" << std::endl;
    }

    std::cout << "Numero de frutas comidas: " << fruits_eaten << std::endl;

    return 0;
}
