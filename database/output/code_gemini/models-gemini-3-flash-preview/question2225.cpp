/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long M;
    if (!(cin >> M)) return 0;

    long long prices[4];
    for (int i = 0; i < 4; ++i) {
        cin >> prices[i];
    }

    int speeds[4] = {80, 100, 120, 80};
    string names[4] = {"Verde", "Vermelho", "Roxo", "Amarelo"};

    int best_idx = -1;

    for (int i = 0; i < 4; ++i) {
        if (prices[i] <= M) {
            if (best_idx == -1) {
                best_idx = i;
            } else {
                // Compare cost-benefit: speeds[i]/prices[i] vs speeds[best_idx]/prices[best_idx]
                // Using cross-multiplication to avoid floating point precision issues:
                // speeds[i] * prices[best_idx] > speeds[best_idx] * prices[i]
                if ((long long)speeds[i] * prices[best_idx] > (long long)speeds[best_idx] * prices[i]) {
                    best_idx = i;
                }
                // If equal, the preference order (1. Verde, 2. Vermelho, 3. Roxo, 4. Amarelo) 
                // means we keep the one with the smaller index. Since we iterate from 0 to 3,
                // the first one encountered with the highest cost-benefit is kept.
            }
        }
    }

    if (best_idx == -1) {
        cout << "Acho que vou a pe :(" << endl;
    } else {
        cout << names[best_idx] << endl;
    }

    return 0;
}