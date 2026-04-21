/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    string cmds;
    cin >> cmds;

    deque<pair<int,int>> snake;
    snake.push_back({N-1, 0});

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    auto dirFromCmd = [&](char c) -> int {
        if (c == 'C') return 0; 
        if (c == 'B') return 1; 
        if (c == 'D') return 2; 
        return 3; 
    };

    for (char ch : cmds) {
        int k = dirFromCmd(ch);
        int r = snake.front().first + dr[k];
        int c = snake.front().second + dc[k];

        bool grow = (grid[r][c] == 'o');

        snake.push_front({r, c});
        if (!grow) snake.pop_back();
        else grid[r][c] = '.';
    }

    cout << snake.size() << "\n";

    vector<string> out(N, string(N, '.'));
    for (auto &p : snake) out[p.first][p.second] = '*';
    for (int i = 0; i < N; i++) cout << out[i] << "\n";

    return 0;
}