/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<int>> board(M, vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) cin >> board[i][j];
    }

    vector<long long> score(N + 1, 0);

    for (int comp = 0; comp < M; comp++) {
        int elimPlayer = -1;
        if (comp + 1 <= N && board[comp][comp] == comp + 1) elimPlayer = comp + 1;

        int t = comp + 1;
        for (int pos = 0; pos < N; pos++) {
            int player = board[comp][pos];
            if (pos + 1 == player && player != 1) continue;
            score[player] += t + (N - (pos + 1));
        }
        if (elimPlayer != -1) {
        }
    }

    vector<int> players;
    players.reserve(N);
    for (int i = 1; i <= N; i++) players.push_back(i);

    auto better = [&](int a, int b) {
        if (score[a] != score[b]) return score[a] > score[b];
        return a < b;
    };

    partial_sort(players.begin(), players.begin() + 3, players.end(), better);

    cout << "O primeiro lugar foi: " << players[0] << "\n";
    cout << "O segundo lugar foi: " << players[1] << "\n";
    cout << "O terceiro lugar foi: " << players[2] << "\n";
    return 0;
}