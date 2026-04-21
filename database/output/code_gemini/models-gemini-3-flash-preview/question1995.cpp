/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int initial_lp;
    if (!(cin >> initial_lp)) return 0;

    int lp[2];
    lp[0] = lp[1] = initial_lp;
    
    int board[2][256];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 256; j++) {
            board[i][j] = 0;
        }
    }

    char type, element;
    int power;
    int turn = 1;

    while (cin >> type) {
        if (!(cin >> element)) break;
        
        int current = (turn % 2 != 0) ? 0 : 1;
        int target = 1 - current;

        if (type == 'C') {
            board[current][(int)element]++;
        } else if (type == 'M') {
            if (!(cin >> power)) break;
            int total_target_creatures = board[target]['F'] + board[target]['G'] + board[target]['T'];
            if (total_target_creatures == 0) {
                lp[target] -= power;
            } else {
                if (board[target][(int)element] > 0) {
                    board[target][(int)element]--;
                }
            }
        }

        if (lp[target] <= 0) break;
        turn++;
    }

    if (lp[1] <= 0) {
        cout << "O jogador 1 ganhou!" << endl;
    } else if (lp[0] <= 0) {
        cout << "O jogador 2 ganhou!" << endl;
    }

    return 0;
}