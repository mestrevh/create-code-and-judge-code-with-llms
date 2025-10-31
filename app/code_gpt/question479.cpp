/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];

    int C;
    cin >> C;
    string commands;
    cin >> commands;

    int x, y;
    cin >> x >> y;

    for (char cmd : commands) {
        int newX = x, newY = y;
        if (cmd == 'D') newY++;
        else if (cmd == 'E') newY--;
        else if (cmd == 'C') newX--;
        else if (cmd == 'B') newX++;

        if (newX >= 0 && newX < N && newY >= 0 && newY < M && grid[newX][newY] == 1) {
            x = newX;
            y = newY;
        }
    }

    cout << "(" << x << "," << y << ")" << endl;
    return 0;
}
