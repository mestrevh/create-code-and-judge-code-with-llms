/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> A(9, vector<int>(9)), B(9, vector<int>(9));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> A[i][j];

    cin.ignore();
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> B[i][j];

    cin.ignore();
    
    string pos;
    int scoreA = 0, scoreB = 0;

    for (int i = 0; i < N; i++) {
        getline(cin, pos);
        int row = pos[0] - 'A';
        int col = pos[1] - '1';

        if (i % 2 == 0) {
            if (A[row][col] == 1) {
                scoreA++;
                A[row][col] = 0;
            }
        } else {
            if (B[row][col] == 1) {
                scoreB++;
                B[row][col] = 0;
            }
        }
    }

    if (scoreA > scoreB)
        cout << "O jogador A venceu" << endl;
    else if (scoreB > scoreA)
        cout << "O jogador B venceu" << endl;
    else
        cout << "Empate" << endl;

    return 0;
}
