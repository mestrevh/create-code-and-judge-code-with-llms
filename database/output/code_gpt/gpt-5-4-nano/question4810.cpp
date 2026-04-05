/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    int goodCount = 0;
    double bestScore = -1.0;
    string bestName;

    for (int i = 0; i < N; i++) {
        string name;
        double P, G, T;
        cin >> name >> P >> G >> T;
        double score = (3.0 * P + G + 2.0 * T) / 6.0;

        if (score >= 3.5) goodCount++;

        if (score > bestScore) {
            bestScore = score;
            bestName = name;
        }
    }

    if (goodCount == 0) {
        cout << "Puts. Melhor ficar em casa mesmo";
    } else {
        cout << "Temos " << goodCount << " lugares pra visitar!\n";
        cout << "Devo comecar por " << bestName;
    }

    return 0;
}