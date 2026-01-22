/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> mapa(N, vector<char>(M));
    pair<int, int> pos_cobra;
    int frutas = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mapa[i][j];
            if (mapa[i][j] == '#') {
                pos_cobra = {i, j};
            } else if (mapa[i][j] == 'O') {
                frutas++;
            }
        }
    }

    int modo;
    cin >> modo;
    string comandos;
    cin >> comandos;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    char direcao[] = {'N', 'S', 'L', 'O'};
    bool game_over = false;
    
    for (char comando : comandos) {
        int direc = (comando == 'N') ? 0 : (comando == 'S') ? 1 : (comando == 'L') ? 2 : 3;
        int nx = pos_cobra.first + dx[direc];
        int ny = pos_cobra.second + dy[direc];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
            if (modo == 1) {
                nx = (nx + N) % N;
                ny = (ny + M) % M;
            } else {
                game_over = true;
                break;
            }
        }

        if (mapa[nx][ny] == '%') {
            game_over = true;
            break;
        }

        if (mapa[nx][ny] == 'O') {
            frutas--;
        }

        mapa[pos_cobra.first][pos_cobra.second] = '.';
        pos_cobra = {nx, ny};
        mapa[nx][ny] = '#';

        if (frutas == 0) {
            break;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << mapa[i][j] << ' ';
        }
        cout << endl;
    }

    if (game_over) {
        cout << " - GAME OVER - " << endl;
    } else if (frutas == 0) {
        cout << "Parabens, voce venceu!" << endl;
    }

    cout << "Numero de frutas comidas: " << (3 - frutas) << endl;
    return 0;
}
