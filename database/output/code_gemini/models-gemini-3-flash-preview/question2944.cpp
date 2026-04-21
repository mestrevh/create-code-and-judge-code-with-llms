/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    int boardA[9][9];
    int shipsA = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (!(cin >> boardA[i][j])) break;
            if (boardA[i][j] == 1) {
                shipsA++;
            }
        }
    }

    int boardB[9][9];
    int shipsB = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (!(cin >> boardB[i][j])) break;
            if (boardB[i][j] == 1) {
                shipsB++;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        string pos;
        if (!(cin >> pos)) break;
        
        if (pos.length() < 2) continue;

        int r = pos[0] - 'A';
        int c = (pos[1] - '0') - 1;

        if (i % 2 == 0) {
            // Turno do Jogador A: Ataca o tabuleiro do Jogador B
            if (r >= 0 && r < 9 && c >= 0 && c < 9) {
                if (boardB[r][c] == 1) {
                    boardB[r][c] = 0;
                    shipsB--;
                }
            }
        } else {
            // Turno do Jogador B: Ataca o tabuleiro do Jogador A
            if (r >= 0 && r < 9 && c >= 0 && c < 9) {
                if (boardA[r][c] == 1) {
                    boardA[r][c] = 0;
                    shipsA--;
                }
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