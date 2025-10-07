/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int calcularMovimentos(vector<vector<int>>& tabuleiro, int x, int y) {
    int movimentos = 0;
    int direcoes[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    
    for (auto& d : direcoes) {
        int nx = x, ny = y;
        while (true) {
            nx += d[0];
            ny += d[1];
            if (nx < 0 || nx >= tabuleiro.size() || ny < 0 || ny >= tabuleiro.size() || tabuleiro[nx][ny] == 1) {
                break;
            }
            movimentos++;
        }
    }
    return movimentos;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> tabuleiro(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tabuleiro[i][j];
        }
    }

    int melhorPontuacao = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tabuleiro[i][j] == 0) {
                melhorPontuacao = max(melhorPontuacao, calcularMovimentos(tabuleiro, i, j));
            }
        }
    }

    cout << melhorPontuacao << endl;
    return 0;
}
