/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int direcoes[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int N, M, minComplexidade = INT_MAX;
vector<vector<int>> labirinto;
vector<vector<bool>> visitado;

void dfs(int x, int y, int dirAnterior, int complexidade) {
    if (x == N - 1 && y == M - 1) {
        minComplexidade = min(minComplexidade, complexidade);
        return;
    }
    
    visitado[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int novoX = x + direcoes[i][0];
        int novoY = y + direcoes[i][1];
        if (novoX >= 0 && novoX < N && novoY >= 0 && novoY < M && labirinto[novoX][novoY] == 1 && !visitado[novoX][novoY]) {
            dfs(novoX, novoY, i, complexidade + (dirAnterior == -1 || dirAnterior == i ? 0 : 1));
        }
    }

    visitado[x][y] = false;
}

int main() {
    cin >> N >> M;
    labirinto.resize(N, vector<int>(M));
    visitado.resize(N, vector<bool>(M, false));
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> labirinto[i][j];

    dfs(0, 0, -1, 0);
    
    if (minComplexidade == INT_MAX) {
        cout << "Continuem cavando!" << endl;
    } else {
        cout << "O caminho tem complexidade: " << minComplexidade << endl;
    }

    return 0;
}
