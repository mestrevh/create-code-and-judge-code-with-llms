/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Y;
    if (!(cin >> N >> Y)) return 0;

    if (N == 0 || Y == 0) {
        cout << "Sharpay endoidou!";
        return 0;
    }

    vector<vector<long long>> a(N, vector<long long>(Y));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Y; j++) cin >> a[i][j];
    }

    bool discovered = false;
    int ansRow = -1, ansCol = -1;

    function<void(int,int)> dfs = [&](int cor, int arm) {
        if (discovered || ansRow != -1) return;
        if (cor < 0 || arm < 0) return;
        if (a[cor][arm] < 0) {
            discovered = true;
            return;
        }
        if (a[cor][arm] == 0) {
            ansRow = cor;
            ansCol = arm;
            return;
        }
        if (cor + 1 < N) {
            dfs(cor + 1, arm);
        } else if (arm + 1 < Y) {
            dfs(0, arm + 1);
        }
    };

    dfs(0, 0);

    if (discovered) {
        cout << "Voce foi descoberto! Corra dancando Bop To the Top!!";
        return 0;
    }

    if (ansRow == -1 || ansCol == -1) {
        cout << "Sharpay endoidou!";
        return 0;
    }

    cout << "O armario a ser invadido fica no corredor " << (ansRow + 1) << ", e e o armario de numero " << (ansCol + 1) << ".";
    return 0;
}