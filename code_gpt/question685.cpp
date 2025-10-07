/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<char>> board(N, vector<char>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    int maxFood = 0, currentFood = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == 'o') currentFood++;
                if (board[i][j] == 'A') {
                    maxFood = max(maxFood, currentFood);
                    currentFood = 0;
                }
            }
        } else {
            for (int j = N - 1; j >= 0; --j) {
                if (board[i][j] == 'o') currentFood++;
                if (board[i][j] == 'A') {
                    maxFood = max(maxFood, currentFood);
                    currentFood = 0;
                }
            }
        }
        maxFood = max(maxFood, currentFood);
    }

    cout << maxFood << endl;
    return 0;
}
