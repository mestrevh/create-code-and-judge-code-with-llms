/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int getGroup(int num) {
    return (num % 100) / 4 + 1;
}

int main() {
    double V;
    int N, M;

    while (true) {
        cin >> V >> N >> M;
        if (V == 0 && N == 0 && M == 0) break;

        int lastFourN = N % 10000;
        int lastFourM = M % 10000;
        int lastThreeN = N % 1000;
        int lastThreeM = M % 1000;
        int lastTwoN = N % 100;
        int lastTwoM = M % 100;

        double prize = 0.0;

        if (lastFourN == lastFourM) prize = V * 3000;
        else if (lastThreeN == lastThreeM) prize = V * 500;
        else if (lastTwoN == lastTwoM) prize = V * 50;
        else if (getGroup(N) == getGroup(M)) prize = V * 16;

        cout << fixed << setprecision(2) << prize << endl;
    }

    return 0;
}
