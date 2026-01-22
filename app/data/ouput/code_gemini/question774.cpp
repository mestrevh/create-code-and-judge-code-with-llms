/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::string> board(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> board[i];
    }

    std::string commands;
    std::cin >> commands;

    int head_row = n - 1;
    int head_col = 0;

    std::deque<std::pair<int, int>> snake_body;
    snake_body.push_front({head_row, head_col});

    for (char cmd : commands) {
        if (cmd == 'C') {
            head_row--;
        } else if (cmd == 'B') {
            head_row++;
        } else if (cmd == 'D') {
            head_col++;
        } else if (cmd == 'E') {
            head_col--;
        }

        snake_body.push_front({head_row, head_col});

        if (board[head_row][head_col] == 'o') {
            board[head_row][head_col] = '.';
        } else {
            snake_body.pop_back();
        }
    }

    std::vector<std::string> output_board(n, std::string(n, '.'));
    for (const auto& part : snake_body) {
        output_board[part.first][part.second] = '*';
    }

    std::cout << snake_body.size() << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << output_board[i] << std::endl;
    }

    return 0;
}
