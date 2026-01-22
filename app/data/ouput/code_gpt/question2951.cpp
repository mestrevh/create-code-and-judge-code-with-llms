/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool isInBounds(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool isCheckMate(char board[N][N], int kx, int ky, char enemyPiece) {
    for (auto [dx, dy] : directions) {
        int nx = kx + dx, ny = ky + dy;
        if (isInBounds(nx, ny) && board[nx][ny] == '-') {
            // Verifica se a casa não está ameaçada
            bool safe = true;
            for (int x = 0; x < N; x++) {
                for (int y = 0; y < N; y++) {
                    if (board[x][y] == enemyPiece) {
                        // Simula o ataque da peça inimiga
                        if (checkAttackingPiece(board, x, y, nx, ny)) {
                            safe = false;
                        }
                    }
                }
            }
            if (safe) return false; // Rei pode se mover para uma posição segura
        }
    }
    return true; // Não pode se mover
}

bool checkAttackingPiece(char board[N][N], int x, int y, int kx, int ky) {
    // Implementar a lógica para verificar se a peça em (x, y) ataca (kx, ky)
    // Dependente da peça, cheque suas regras de movimento
    return false; // Exemplo simplificado
}

int main() {
    char board[N][N];
    int kx = -1, ky = -1;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'k') {
                kx = i;
                ky = j;
            }
        }

    bool inCheck = false;
    char enemyPiece = 't'; // Exemplo, ajuste conforme as regras do seu tabuleiro

    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++) {
            if (board[x][y] == enemyPiece) {
                if (checkAttackingPiece(board, x, y, kx, ky)) {
                    inCheck = true;
                }
            }
        }

    if (inCheck && isCheckMate(board, kx, ky, enemyPiece)) {
        cout << "XEQUE-MATE" << endl;
    } else if (inCheck) {
        cout << "XEQUE" << endl;
    } else {
        cout << "NAO XEQUE" << endl;
    }

    return 0;
}
