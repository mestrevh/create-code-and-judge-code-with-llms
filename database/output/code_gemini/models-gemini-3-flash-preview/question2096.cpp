/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    int boardA[9][9];
    int boardB[9][9];

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> boardA[i][j];
        }
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> boardB[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        string pos;
        cin >> pos;
        
        int r = pos[0] - 'A';
        int c = pos[1] - '1';

        if (i % 2 == 0) {
            // Player A's turn: attacks Player B
            if (r >= 0 && r < 9 && c >= 0 && c < 9) {
                boardB[r][c] = 0;
            }
        } else {
            // Player B's turn: attacks Player A
            if (r >= 0 && r < 9 && c >= 0 && c < 9) {
                boardA[r][c] = 0;
            }
        }
    }

    int countA = 0;
    int countB = 0;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (boardA[i][j] == 1) countA++;
            if (boardB[i][j] == 1) countB++;
        }
    }

    if (countA > countB) {
        cout << "O jogador A venceu" << endl;
    } else if (countB > countA) {
        cout << "O jogador B venceu" << endl;
    } else {
        cout << "Empate" << endl;
    }

    return 0;
}