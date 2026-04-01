/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int grid[10][10];
bool visited[10][10];

bool solveMaze(int r, int c) {
    if (r < 0 || r >= 10 || c < 0 || c >= 10 || grid[r][c] == 0 || visited[r][c])
        return false;
    if (r == 9 && c == 9)
        return true;

    visited[r][c] = true;

    if (solveMaze(r + 1, c)) return true;
    if (solveMaze(r - 1, c)) return true;
    if (solveMaze(r, c + 1)) return true;
    if (solveMaze(r, c - 1)) return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= 0 && x <= n) {
            cnt[x]++;
        }
    }

    bool possible = false;
    for (int k = 1; k <= n; k++) {
        if (cnt[k] == k) {
            possible = true;
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    if (possible) {
        cout << "Vamos nessa, temos que sair rapido..." << endl;
        if (solveMaze(0, 0)) {
            cout << "Tudo nosso." << endl;
        } else {
            cout << "Continuem cavando!" << endl;
        }
    } else {
        cout << "Ja nao se pode confiar nos refens como antigamente..." << endl;
    }

    return 0;
}