/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V;
    while (cin >> V) {
        int P;
        if (!(cin >> P)) break;

        long long sumCelo = 0;
        for (int i = 0; i < P; ++i) {
            double g;
            cin >> g;
            sumCelo += (long long)round(g * 100.0);
        }

        int C;
        if (!(cin >> C)) break;

        int countBetter = 0;
        for (int i = 0; i < C; ++i) {
            int CP;
            if (!(cin >> CP)) break;
            long long sumComp = 0;
            for (int j = 0; j < CP; ++j) {
                double g;
                cin >> g;
                sumComp += (long long)round(g * 100.0);
            }

            bool better = false;
            if (sumComp * P > sumCelo * CP) {
                better = true;
            } else if (sumComp * P == sumCelo * CP) {
                if (CP > P) {
                    better = true;
                }
            }

            if (better) {
                countBetter++;
            }
        }

        int rankCelo = countBetter + 1;

        if (rankCelo <= V) {
            cout << "Matriculado, seu ranking é " << rankCelo << " dentre as " << V << " vagas" << endl;
        } else {
            cout << "Se não tivesse pago Dominó " << P << ", teria entrado..." << endl;
        }
    }

    return 0;
}