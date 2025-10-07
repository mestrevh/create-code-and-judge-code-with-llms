/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    vector<vector<int>> board(N, vector<int>(N, 0));
    
    for (int i = 0; i < P; ++i) {
        int L, C;
        cin >> L >> C;
        board[L - 1][C - 1] = 1; // Pedra preta
    }
    
    for (int i = 0; i < P; ++i) {
        int L, C;
        cin >> L >> C;
        board[L - 1][C - 1] = 2; // Pedra branca
    }

    vector<vector<int>> countBlack(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> countWhite(N + 1, vector<int>(N + 1, 0));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            countBlack[i + 1][j + 1] = countBlack[i][j + 1] + countBlack[i + 1][j] - countBlack[i][j];
            countWhite[i + 1][j + 1] = countWhite[i][j + 1] + countWhite[i + 1][j] - countWhite[i][j];
        
            if (board[i][j] == 1) countBlack[i + 1][j + 1]++;
            if (board[i][j] == 2) countWhite[i + 1][j + 1]++;
        }
    }

    int blackAreas = 0, whiteAreas = 0;

    for (int size = 1; size <= N; ++size) {
        for (int i = 0; i <= N - size; ++i) {
            for (int j = 0; j <= N - size; ++j) {
                int blackCount = countBlack[i + size][j + size] - countBlack[i][j + size] - countBlack[i + size][j] + countBlack[i][j];
                int whiteCount = countWhite[i + size][j + size] - countWhite[i][j + size] - countWhite[i + size][j] + countWhite[i][j];

                if (blackCount > 0 && whiteCount == 0) blackAreas++;
                if (whiteCount > 0 && blackCount == 0) whiteAreas++;
            }
        }
    }

    cout << blackAreas << " " << whiteAreas << endl;
    return 0;
}
