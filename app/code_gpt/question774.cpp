/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> board(N, string(N, '.'));
    string commands;
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }
    cin >> commands;

    int x = N - 1, y = 0;
    vector<pair<int, int>> snake = {{x, y}};
    
    for (char cmd : commands) {
        if (cmd == 'C') x--;
        else if (cmd == 'B') x++;
        else if (cmd == 'D') y++;
        else if (cmd == 'E') y--;

        snake.push_back({x, y});
        if (board[x][y] == 'o') {
            board[x][y] = '.';
        } else {
            snake.erase(snake.begin());
        }
    }

    cout << snake.size() << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (find(snake.begin(), snake.end(), make_pair(i, j)) != snake.end()) {
                cout << '*';
            } else {
                cout << board[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
