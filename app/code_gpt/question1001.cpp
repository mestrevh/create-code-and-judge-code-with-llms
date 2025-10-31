/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

const int dx[5] = {0, 1, 1, -1, -1};
const int dy[5] = {0, 1, -1, -1, 1};

void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> matrix(N, vector<int>(M, 0));    
    vector<pair<int, int>> ships(K);

    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        ships[i] = {x, y};
        matrix[x][y] = 1; // place ship
    }

    int H, B;
    cin >> H >> B;

    displayMatrix(matrix);

    for (int h = 0; h < H; ++h) {
        for (int b = 0; b < B; ++b) {
            int x, y;
            cin >> x >> y;

            // Bomb effect
            for (int j = 0; j < 5; ++j) {
                int nx = (x + dx[j] + N) % N;
                int ny = (y + dy[j] + M) % M;
                matrix[nx][ny] = 0;
            }
        }

        // Move ships
        for (auto& ship : ships) {
            int x = ship.first;
            int y = ship.second;
            matrix[x][y] = 0; // remove old position
            x = (x - 1 + N) % N;
            y = (y + 1) % M;
            ship.first = x;
            ship.second = y;
            matrix[x][y] = 1; // new position
        }

        displayMatrix(matrix);
    }

    return 0;
}
