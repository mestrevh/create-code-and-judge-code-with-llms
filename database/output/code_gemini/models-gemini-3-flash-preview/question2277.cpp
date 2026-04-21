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

    vector<long long> P(N + 1);
    bool all_enemies = true;
    for (int i = 1; i <= N; ++i) {
        if (!(cin >> P[i])) break;
        if (P[i] > 0) {
            all_enemies = false;
        }
    }

    if (all_enemies) {
        cout << "E uma armadilha" << endl;
        return 0;
    }

    long long maxSum = -4e18; 
    int bestX = -1, bestY = -1;
    long long minPrefix = 0;
    int bestStartXForCurrentY = 1;
    long long currentPrefix = 0;

    for (int i = 1; i <= N; ++i) {
        currentPrefix += P[i];
        long long currentMaxSumEndingAtI = currentPrefix - minPrefix;

        if (currentMaxSumEndingAtI >= maxSum) {
            maxSum = currentMaxSumEndingAtI;
            bestX = bestStartXForCurrentY;
            bestY = i;
        }

        if (currentPrefix <= minPrefix) {
            minPrefix = currentPrefix;
            bestStartXForCurrentY = i + 1;
        }
    }

    if (bestX == bestY) {
        cout << "Naruto deve libertar somente a posicao " << bestX << endl;
    } else {
        cout << "Naruto deve libertar da posicao " << bestX << " ate a posicao " << bestY << endl;
    }

    return 0;
}