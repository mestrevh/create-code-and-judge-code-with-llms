/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> pos(M, vector<int>(N));
    vector<long long> pontos(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> pos[i][j];
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int jogador = pos[i][j];
            if (jogador != (j + 1) || i == 0) {
                pontos[jogador] += (i + 1) * (N - j);
            }
        }
    }

    vector<pair<long long, int>> ranking;
    for (int i = 1; i <= N; ++i) {
        ranking.push_back({pontos[i], i});
    }
    
    sort(ranking.rbegin(), ranking.rend());

    cout << "O primeiro lugar foi: " << ranking[0].second << endl;
    cout << "O segundo lugar foi: " << ranking[1].second << endl;
    cout << "O terceiro lugar foi: " << ranking[2].second << endl;

    return 0;
}
