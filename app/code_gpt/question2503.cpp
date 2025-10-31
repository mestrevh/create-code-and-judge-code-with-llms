/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

const int N = 10;
int maze[N][N];
bool visited[N][N];

bool canEscape(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N || maze[x][y] == 0 || visited[x][y]) return false;
    if (x == N - 1 && y == N - 1) return true;
    visited[x][y] = true;
    bool result = canEscape(x + 1, y) || canEscape(x - 1, y) || canEscape(x, y + 1) || canEscape(x, y - 1);
    visited[x][y] = false;
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> truths(n);
    for(int i = 0; i < n; i++) cin >> truths[i];

    bool hasTruth = false;
    for(int i : truths) {
        if(i >= n - 1) {
            hasTruth = true;
            break;
        }
    }

    if(hasTruth) {
        cout << "Vamo nessa, temos que sair rapido...\n";
        memset(visited, false, sizeof(visited));
        if(canEscape(0, 0)) {
            cout << "Tudo nosso.\n";
        } else {
            cout << "Continuem cavando!\n";
        }
    } else {
        cout << "Ja nao se pode confiar nos refens como antigamente...\n";
    }

    return 0;
}
