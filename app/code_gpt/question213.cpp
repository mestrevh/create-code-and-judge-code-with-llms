/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<char>> mapa(M, vector<char>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> mapa[i][j];
        }
    }

    int direcoes[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int costa = 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (mapa[i][j] == '#') {
                bool adjacente_a_agua = false;
                for (const auto& dir : direcoes) {
                    int ni = i + dir[0], nj = j + dir[1];
                    if (ni < 0 || ni >= M || nj < 0 || nj >= N || mapa[ni][nj] == '.') {
                        adjacente_a_agua = true;
                        break;
                    }
                }
                if (adjacente_a_agua) {
                    costa++;
                }
            }
        }
    }

    cout << costa << endl;
    return 0;
}
