/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

float vantagem(float candidato[], float concorrente[], int n) {
    float best = 0.0f;
    for (int i = 0; i < n; i++) {
        if (candidato[i] > concorrente[i]) {
            best = max(best, candidato[i] - concorrente[i]);
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<float> candidato(n), concorrente(n);
    for (int i = 0; i < n; i++) cin >> candidato[i];
    for (int i = 0; i < n; i++) cin >> concorrente[i];

    cout << fixed << setprecision(2) << vantagem(candidato.data(), concorrente.data(), n) << "\n";
    return 0;
}