/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> boardA(9, vector<int>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> boardA[i][j];
        }
    }

    vector<vector<int>> boardB(9, vector<int>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> boardB[i][j];
        }
    }

    int shipsA = 0;
    int shipsB = 0;

    for (int i = 0; i < n; ++i) {
        string move;
        cin >> move;
        int row = move[0] - 'A';
        int col = move[1] - '1';

        if (i % 2 == 0) {
            if (boardB[row][col] == 1) {
                shipsA++;
                boardB[row][col] = 0;
            }
        } else {
            if (boardA[row][col] == 1) {
                shipsB++;
                boardA[row][col] = 0;
            }
        }
    }

    if (shipsA > shipsB) {
        cout << "O jogador A venceu" << endl;
    } else if (shipsB > shipsA) {
        cout << "O jogador B venceu" << endl;
    } else {
        cout << "Empate" << endl;
    }

    return 0;
}
