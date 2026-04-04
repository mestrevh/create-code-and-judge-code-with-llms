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

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> boardA(9, vector<int>(9));
    vector<vector<int>> boardB(9, vector<int>(9));

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

    for (int i = 0; i < n; ++i) {
        string coord;
        cin >> coord;
        if (coord.empty()) {
            i--;
            continue;
        }

        int r = coord[0] - 'A';
        int c = coord[1] - '1';

        if (i % 2 == 0) {
            // Jogador A ataca o tabuleiro do Jogador B
            if (r >= 0 && r < 9 && c >= 0 && c < 9) {
                boardB[r][c] = 0;
            }
        } else {
            // Jogador B ataca o tabuleiro do Jogador A
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