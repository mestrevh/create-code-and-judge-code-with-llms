/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int m, n, x, y;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(m));
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                x = i;
                y = j;
            }
        }
    }

    string move;
    for (int i = 0; i < n; ++i) {
        cin >> move;

        if (move == "D") {
            y = (y + 1) % m;
        } else if (move == "E") {
            y = (y - 1 + m) % m;
        } else if (move == "C") {
            x = (x - 1 + m) % m;
        } else if (move == "B") {
            x = (x + 1) % m;
        }

        if (grid[x][y] == '@') {
            cout << "Game over." << endl;
            return 0;
        }
    }

    grid[x][y] = '#';
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
