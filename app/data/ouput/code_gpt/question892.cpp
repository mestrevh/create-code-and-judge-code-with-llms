/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool canAttackAllEnemies(int H, int C, vector<string>& map) {
    vector<vector<bool>> attacked(H, vector<bool>(C, false));
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < C; ++j) {
            if (map[i][j] == '&') {
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (abs(di) + abs(dj) == 1) {
                            int ni = i + di;
                            int nj = j + dj;
                            if (ni >= 0 && ni < H && nj >= 0 && nj < C && map[ni][nj] == '*') {
                                attacked[ni][nj] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < C; ++j) {
            if (map[i][j] == '*' && !attacked[i][j]) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int H, C;
    cin >> H >> C;
    vector<string> map(H);
    for (int i = 0; i < H; ++i) {
        cin >> map[i];
    }
    
    cout << (canAttackAllEnemies(H, C, map) ? "S" : "N") << endl;
    return 0;
}
