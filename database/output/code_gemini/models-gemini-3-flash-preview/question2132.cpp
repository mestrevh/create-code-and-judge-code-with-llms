/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<pair<int, int>> config(N);
    for (int i = 0; i < N; ++i) {
        cin >> config[i].first >> config[i].second;
    }

    long long P;
    cin >> P;

    // A matriz (jagged array) conforme solicitado
    vector<vector<int>> naves(N);

    for (int i = 0; i < N; ++i) {
        int setores = config[i].first;
        int capacidade = config[i].second;
        naves[i].resize(setores);

        for (int j = 0; j < setores; ++j) {
            if (P >= (long long)capacidade) {
                naves[i][j] = capacidade;
                P -= capacidade;
            } else {
                naves[i][j] = (int)P;
                P = 0;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < (int)naves[i].size(); ++j) {
            cout << "Nave " << i + 1 << " - Setor " << j + 1 << ": " << naves[i][j] << " pessoa(s)\n";
        }
    }

    cout << "Pessoas nao evacuadas: " << P << " pessoa(s)" << endl;

    return 0;
}

// Complexidade de Tempo: O(Total de Setores)
// Complexidade de Espaço: O(Total de Setores)