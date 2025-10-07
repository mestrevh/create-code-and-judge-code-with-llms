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
    vector<vector<char>> board(N, vector<char>(N, '.'));
    
    board[0][0] = 'A';
    for (int i = 1; i < N; i++) {
        if (i % 2 == 0) {
            for (int j = 1; j < N; j += 2) {
                board[i][j] = 'A';
            }
        } else {
            for (int j = 0; j < N; j += 2) {
                board[i][j] = 'A';
            }
        }
    }
    
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell;
        }
        cout << endl;
    }
    return 0;
}
