/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double V, fuel;
    if (!(cin >> V >> fuel)) return 0;
    long long Dll;
    cin >> Dll;
    double D = (double)Dll;

    if (D < 0) {
        cout << "Vai pa onde, kinho?";
        return 0;
    }

    if (V < 75.0) {
        cout << "Zilboi trollou o kinho";
        return 0;
    }

    double remainingFuel = fuel;
    double distanceLeft = D;

    double battery = V;

    auto clampSeg = [&](double x, double lo, double hi) -> double {
        if (x < lo) return lo;
        if (x > hi) return hi;
        return x;
    };

    double segLen1 = min(5.0, distanceLeft);
    distanceLeft -= segLen1;
    if (distanceLeft <= 0) {
        cout << "Parabens, Kinho. Vc vai comer um morceguinho.";
        return 0;
    }

    double batteryAfter5 = battery - 10.0;
    battery = batteryAfter5;

    if (battery >= 50.0) {
        double consumedPerKm = 1.0 / 13.0;
        while (distanceLeft > 1e-12) {
            if (battery < 50.0) break;

            double baseDist = 5.0 + 2.5 * 0.5; // 6.25? not needed
            int step = 0;

            double curDistanceFromStart = D - distanceLeft;
            int i = (int)floor((curDistanceFromStart - 5.0) / 2.5 + 1e-12);
            if (i < 0) i = 0;

            double nextBoundary = 5.0 + 2.5 * (i + 1);
            double boundaryRemaining = nextBoundary - curDistanceFromStart;
            double segLen = min(distanceLeft, boundaryRemaining);

            double consKmL = 13.0 - 0.5 * i;
            if (segLen <= 1e-12) {
                nextBoundary += 2.5;
                continue;
            }

            double maxDistWithBattery = 2.5 * ((battery - 50.0) / 5.0);
            double segByBattery = min(segLen, maxDistWithBattery);
            if (segByBattery > 1e-12) {
                double neededFuel = segByBattery / consKmL;
                if (remainingFuel + 1e-12 < neededFuel) {
                    cout << "Pobre Kinho. Vai ficar no meio do caminho.";
                    return 0;
                }
                remainingFuel -= neededFuel;
                distanceLeft -= segByBattery;
                battery -= 5.0 * (segByBattery / 2.5);
            } else {
                break;
            }

            if (segLen - segByBattery > 1e-9) break;
        }
    }

    if (distanceLeft <= 1e-12) {
        cout << "Parabens, Kinho. Vc vai comer um morceguinho.";
        return 0;
    }

    if (distanceLeft > 0) {
        if (battery < 50.0) {
            double cons = 10.0;
            double neededFuel = distanceLeft / cons;
            if (remainingFuel + 1e-12 >= neededFuel) {
                cout << "Parabens, Kinho. Vc vai comer um morceguinho.";
            } else {
                cout << "Pobre Kinho. Vai ficar no meio do caminho.";
            }
        } else {
            cout << "Parabens, Kinho. Vc vai comer um morceguinho.";
        }
    }

    return 0;
}