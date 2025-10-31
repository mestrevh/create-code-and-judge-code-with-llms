/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, B;
    cin >> N >> B;
    vector<vector<char>> board(N, vector<char>(N, '-'));
    
    for (int i = 0; B > 0 && i < N * N; ++i) {
        if (B & 1) {
            board[i / N][i % N] = 'x';
        }
        B >>= 1;
    }

    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }
    
    return 0;
}
