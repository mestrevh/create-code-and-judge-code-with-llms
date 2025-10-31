/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    double X, Y, Z;
    while (cin >> X >> Y >> Z, X || Y || Z) {
        int P, M, G;
        cin >> P >> M >> G;

        int area = static_cast<int>(X * Y * 10000); // cm²
        int tile5 = 25, tile15 = 225, tile30 = 900; // cm²
        int cost5 = 2, cost15 = 15, cost30 = 50;

        int totalTiles = area / tile5 + (area % tile5 != 0);
        int maxCost = totalTiles * cost5;
        int minTilesP = min(P, area / tile5);
        area -= minTilesP * tile5;

        int minTilesM = min(M, area / tile15);
        area -= minTilesM * tile15;

        int minTilesG = area / tile30;
        if (minTilesG > G) minTilesG = G;
        area -= minTilesG * tile30;

        if (area > 0) {
            cout << "impossivel" << endl;
        } else {
            int totalCost = minTilesP * cost5 + minTilesM * cost15 + minTilesG * cost30;
            if (totalCost > maxCost) {
                cout << "impossivel" << endl;
            } else {
                cout << minTilesP << " " << minTilesM << " " << minTilesG << endl;
            }
        }
    }
    return 0;
}
