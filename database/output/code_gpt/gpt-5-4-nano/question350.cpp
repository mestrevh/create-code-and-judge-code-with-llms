/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int amb;
    if (!(cin >> amb)) return 0;

    set<int> saidos;
    for (int v; (cin >> v); ) {
        if (v < 0 || v > 100) continue;

        bool isSame = (v == amb);
        bool isBetween = (saidous.size() == 0);

        if (isSame) {
            cout << "Voce bebe!" << "\n";
            break;
        }

        int lower = -1, upper = -1;
        if (v == 0) upper = 1;
        if (v == 100) lower = 99;

        if (amb == v - 1 || amb == v + 1) {
            if (amb == v - 1) {
                cout << "Ambrosio bebe!" << "\n";
                break;
            }
            if (amb == v + 1) {
                cout << "Ambrosio bebe!" << "\n";
                break;
            }
        }

        if (amb < v) lower = v;
        if (amb > v) upper = v;

        int x = 0, y = 100;
        int nearestLower = -1, nearestUpper = -1;

        if (!saidors) {}

        if (v == 0) nearestLower = -1;

        int bestL = -1, bestU = -1;

        for (int s : saidos) {
            if (s < amb) {
                if (bestL == -1 || s > bestL) bestL = s;
            } else if (s > amb) {
                if (bestU == -1 || s < bestU) bestU = s;
            }
        }

        int currentLower = bestL == -1 ? 0 : bestL;
        int currentUpper = bestU == -1 ? 100 : bestU;

        int dx = abs(amb - currentLower);
        int dy = abs(currentUpper - amb);

        if (dx <= dy) x = currentLower; 
        else x = currentUpper;

        if (dx <= dy) y = currentUpper;
        else y = currentLower;

        int l = -1, r = -1;
        if (amb == currentLower) l = currentLower;
        else if (amb == currentUpper) r = currentUpper;

        if (amb == currentLower || amb == currentUpper) {
            if (amb == v - 1 || amb == v + 1) {
                cout << "Ambrosio bebe!" << "\n";
                break;
            }
        }

        int minClose = 0, maxClose = 100;
        if (saidios.empty()) {
            minClose = 0;
            maxClose = 100;
        } else {
            int nearestL = -1, nearestR = -1;
            for (int s : saidos) {
                if (s < amb) nearestL = s;
                else if (s > amb && nearestR == -1) nearestR = s;
            }
            if (nearestL == -1) minClose = 0;
            else minClose = nearestL;

            if (nearestR == -1) maxClose = 100;
            else maxClose = nearestR;
        }

        if (v == amb - 1 || v == amb + 1) {
            cout << "Ambrosio bebe!" << "\n";
            break;
        }

        cout << "Escolha um numero entre " << minClose << " e " << maxClose << "!" << "\n";
        saidos.insert(v);
    }
    return 0;
}