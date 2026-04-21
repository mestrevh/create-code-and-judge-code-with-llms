/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // Knight moves: 1 to 8 offsets
    // M1: (1, 2), M2: (2, 1), M3: (2, -1), M4: (1, -2)
    // M5: (-1, -2), M6: (-2, -1), M7: (-2, 1), M8: (-1, 2)
    int dx[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {0, 2, 1, -1, -2, -2, -1, 1, 2};

    // Holes coordinates
    bool hole[8][8] = {false};
    hole[1][3] = true;
    hole[2][3] = true;
    hole[2][5] = true;
    hole[5][4] = true;

    int curX = 4, curY = 3;
    int movesCount = 0;
    bool fell = false;

    for (int i = 0; i < N; ++i) {
        int m;
        cin >> m;
        
        if (fell) continue;

        curX += dx[m];
        curY += dy[m];
        movesCount++;

        if (curX >= 0 && curX < 8 && curY >= 0 && curY < 8) {
            if (hole[curX][curY]) {
                fell = true;
            }
        }
    }

    cout << movesCount << endl;

    return 0;
}

// O programa simula o passeio do cavalo em um tabuleiro 8x8.
// As coordenadas iniciais são (4,3). 
// Existem buracos em (1,3), (2,3), (2,5) e (5,4).
// O passeio termina ao processar todos os N movimentos ou ao cair em um buraco.