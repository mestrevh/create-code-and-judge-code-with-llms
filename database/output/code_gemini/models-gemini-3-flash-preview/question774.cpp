/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> board(N);
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    string commands;
    cin >> commands;

    deque<pair<int, int>> snake;
    snake.push_back({N - 1, 0});

    for (char cmd : commands) {
        pair<int, int> head = snake.front();
        int nr = head.first;
        int nc = head.second;

        if (cmd == 'C') nr--;
        else if (cmd == 'B') nr++;
        else if (cmd == 'D') nc++;
        else if (cmd == 'E') nc--;

        if (board[nr][nc] == 'o') {
            board[nr][nc] = '.';
            snake.push_front({nr, nc});
        } else {
            snake.push_front({nr, nc});
            snake.pop_back();
        }
    }

    cout << snake.size() << "\n";

    vector<string> result(N, string(N, '.'));
    for (auto const& p : snake) {
        result[p.first][p.second] = '*';
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}

