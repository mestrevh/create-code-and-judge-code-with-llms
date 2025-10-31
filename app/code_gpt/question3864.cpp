/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string dimensions;
    getline(cin, dimensions);
    int m, n;
    sscanf(dimensions.c_str(), "%dx%d", &m, &n);

    int total_positions = m * n;
    
    int num_bombs;
    cin >> num_bombs;

    vector<vector<int>> market(m, vector<int>(n, 0));
    
    if (num_bombs >= total_positions) {
        cout << "BANDECLAY OVERLOAD!" << endl;
        return 0;
    }

    string bombs_input;
    cin.ignore();
    getline(cin, bombs_input);
    istringstream ss(bombs_input);
    string bomb;
    
    while (ss >> bomb) {
        char x = bomb[0];
        int y = bomb[1] - '1';

        int col = x - 'a';
        if (y >= 0 && y < m && col >= 0 && col < n) {
            market[y][col] = 9;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) continue;
                    int ny = y + i, nx = col + j;
                    if (ny >= 0 && ny < m && nx >= 0 && nx < n && market[ny][nx] != 9) {
                        market[ny][nx]++;
                    }
                }
            }
        }
    }

    for (const auto &row : market) {
        for (int i = 0; i < n; i++) {
            cout << row[i];
            if (i < n - 1) cout << " ";
        }
        cout << " " << endl;
    }
    
    return 0;
}
