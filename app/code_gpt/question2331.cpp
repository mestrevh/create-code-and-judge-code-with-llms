/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

const int N = 10;
int labirinto[N][N];
bool visitado[N][N];

bool dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N || labirinto[x][y] == 0 || visitado[x][y])
        return false;

    if (x == 9 && y == 9)
        return true;

    visitado[x][y] = true;

    if (dfs(x + 1, y)) return true; // Sul
    if (dfs(x, y + 1)) return true; // Leste
    if (dfs(x - 1, y)) return true; // Norte
    if (dfs(x, y - 1)) return true; // Oeste

    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> refens(n);
    int contagem = 0;

    for (int i = 0; i < n; ++i) {
        cin >> refens[i];
        if (refens[i] == n - 1)
            contagem++;
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> labirinto[i][j];

    if (contagem > 0)
        cout << "Vamo nessa, temos que sair rapido..." << endl;
    else
        cout << "Ja nao se pode confiar nos refens como antigamente..." << endl;

    memset(visitado, false, sizeof(visitado));
    if (contagem > 0 && dfs(0, 0))
        cout << "Tudo nosso." << endl;
    else
        cout << "Continuem cavando!" << endl;

    return 0;
}
