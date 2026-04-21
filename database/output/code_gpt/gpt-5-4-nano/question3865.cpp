/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, tamX, tamY;
    if (!(cin >> N >> tamX >> tamY)) return 0;

    vector<pair<int,int>> coords(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        coords[i] = {x, y};
    }

    vector<vector<int>> board(tamX, vector<int>(tamY));
    for (int i = 0; i < tamX; i++) {
        for (int j = 0; j < tamY; j++) {
            cin >> board[i][j];
        }
    }

    long long best = 0;
    for (auto [x, y] : coords) {
        int row = x, col = y;
        vector<int> cnt(5, 0);

        for (int j = 0; j < tamY; j++) cnt[board[row][j]]++;
        for (int i = 0; i < tamX; i++) cnt[board[i][col]]++;

        int cell = board[row][col];
        cnt[cell]--; 

        long long cur = 0;
        for (int t = 1; t <= 4; t++) cur = max<long long>(cur, cnt[t]);

        best = max(best, cur);
    }

    cout << "A pontuacao da equipe vencedora sera " << best << " ponto(s)!";
    return 0;
}