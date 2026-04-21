/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    if (!(cin >> N >> M)) return 0;

    int currX = 0, currY = 0, currZ = 0;
    long long totalMoves = 0;
    bool fuelOut = false;
    int deliveredCount = 0;

    for (int i = 1; i <= 4 * N; ++i) {
        int room;
        if (!(cin >> room)) break;

        if (fuelOut) continue;

        int tx = room / 100;
        int ty = (room / 10) % 10;
        int tz = room % 10;

        int dx = tx - currX;
        int dy = ty - currY;
        int dz = tz - currZ;

        // Sequence of movements: X, then Y, then Z
        if (dx > 0) {
            for (int k = 0; k < dx; ++k) cout << 'd';
        } else if (dx < 0) {
            for (int k = 0; k < -dx; ++k) cout << 'e';
        }

        if (dy > 0) {
            for (int k = 0; k < dy; ++k) cout << 'c';
        } else if (dy < 0) {
            for (int k = 0; k < -dy; ++k) cout << 'b';
        }

        if (dz > 0) {
            for (int k = 0; k < dz; ++k) cout << 'f';
        } else if (dz < 0) {
            for (int k = 0; k < -dz; ++k) cout << 't';
        }
        cout << "\n";

        int tripCost = (dx < 0 ? -dx : dx) + (dy < 0 ? -dy : dy) + (dz < 0 ? -dz : dz);
        totalMoves += tripCost;
        deliveredCount++;

        cout << "Entregue " << i << " no quarto " << setfill('0') << setw(3) << room << " com " << totalMoves << " movimentos\n";

        currX = tx;
        currY = ty;
        currZ = tz;

        if (totalMoves > M) {
            fuelOut = true;
        }
    }

    if (!fuelOut) {
        cout << "Todas as pessoas foram entregues.\n";
    } else {
        cout << "Faltou combustivel e foram entregues " << deliveredCount << " pessoas.\n";
    }
    cout << "Fim do teste. Obrigado Kanye West!" << endl;

    return 0;
}