/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

char M[8][8];
int dx[2] = {-1, -1};
int dy[2] = {1, -1};

bool isCapture(int x, int y, int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) return false;
    if (M[nx][ny] != '%' && M[nx][ny] != '*') return false;

    nx += dx[dir];
    ny += dy[dir];
    return nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && M[nx][ny] == '*';
}

void capture(int& x, int& y, int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    M[nx][ny] = '*';
    x += dx[dir] * 2;
    y += dy[dir] * 2;
}

int main() {
    for (int i = 0; i < 8; ++i) 
        for (int j = 0; j < 8; ++j) 
            cin >> M[i][j];

    int N;
    cin >> N;

    int piecesCaptured = 0;
    bool hasSopro = false;
    int x, y;

    for (int i = 0; i < 8; ++i) 
        for (int j = 0; j < 8; ++j) 
            if (M[i][j] == '#') {
                x = i;
                y = j;
            }

    string movements;
    for (int i = 0; i < N; ++i) {
        char move;
        cin >> move;
        int dir = (move == 'D') ? 0 : 1;

        if (isCapture(x, y, dir)) {
            int prevX = x, prevY = y;
            capture(x, y, dir);
            piecesCaptured++;
            cout << "Voce capturou uma peca na casa (" << prevX + 1 << "," << prevY + 1 << ") e avancou para a casa (" << x + 1 << "," << y + 1 << ")." << endl;
            hasSopro = false;
        } else {
            int newX = x + dx[dir];
            int newY = y + dy[dir];
            if (M[newX][newY] == '*') {
                cout << "Voce deveria ter capturado a peca na casa (" << newX + 1 << "," << newY + 1 << ")." << endl;
                hasSopro = true;
            } else {
                cout << "Voce avancou para a casa (" << newX + 1 << "," << newY + 1 << ")." << endl;
                x = newX;
                y = newY;
            }
        }
    }
    
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "Voce capturou " << piecesCaptured << " pecas." << endl;
    if (hasSopro) cout << "Deu sopro." << endl;

    return 0;
}
