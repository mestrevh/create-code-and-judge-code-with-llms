/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count[4][4] = {0};

    int x = 0, y = 0;
    count[x][y]++;

    for (int i = 0; i < 20; ++i) {
        char move;
        if (!(cin >> move)) break;
        if (move == 'c') {
            if (y > 0) y--;
        } else if (move == 'b') {
            if (y < 3) y++;
        } else if (move == 'e') {
            if (x > 0) x--;
        } else if (move == 'd') {
            if (x < 3) x++;
        }
        count[x][y]++;
    }

    int maxV = -1;
    int ansX = 0, ansY = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (count[j][i] > maxV) {
                maxV = count[j][i];
                ansX = j;
                ansY = i;
            }
        }
    }

    cout << "Coordenada X:" << ansX << ", Y:" << ansY << endl;

    return 0;
}