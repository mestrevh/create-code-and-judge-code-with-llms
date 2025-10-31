/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N, M, movements = 0, delivered = 0;
    cin >> N >> M;
    vector<vector<int>> rooms(4, vector<int>(N * 4));

    for (int i = 0; i < N * 4; i++) {
        cin >> rooms[i % 4][i / 4];
    }

    int x = 0, y = 0, z = 0;
    for (int p = 0; p < N * 4; p++) {
        int targetX = rooms[0][p], targetY = rooms[1][p], targetZ = rooms[2][p];
        string move;

        int dx = targetX - x, dy = targetY - y, dz = targetZ - z;

        if (dx > 0) move += string(dx, 'd'), movements += dx;
        else if (dx < 0) move += string(-dx, 'e'), movements += -dx;

        if (dy > 0) move += string(dy, 'c'), movements += dy;
        else if (dy < 0) move += string(-dy, 'b'), movements += -dy;

        if (dz > 0) move += string(dz, 'f'), movements += dz;
        else if (dz < 0) move += string(-dz, 't'), movements += -dz;

        delivered++;
        cout << move << endl;
        cout << "Entregue " << delivered << " no quarto " << targetX << targetY << targetZ << " com " << movements << " movimentos" << endl;

        if (movements > M) {
            cout << "Faltou combustível e foram entregues " << delivered << " pessoas." << endl;
            break;
        }

        x = targetX;
        y = targetY;
        z = targetZ;
    }

    if (delivered == N * 4) {
        cout << "Todas as pessoas foram entregues." << endl;
    }
    cout << "Fim do teste. Obrigado Kanye West!" << endl;

    return 0;
}
