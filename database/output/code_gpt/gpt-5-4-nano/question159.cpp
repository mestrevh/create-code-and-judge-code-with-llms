/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, X, Y, K;
    if (!(cin >> N >> M >> X >> Y >> K)) return 0;

    vector<vector<char>> blocked(N + 1, vector<char>(M + 1, 0));
    for (int i = 0; i < K; i++) {
        int A, B;
        cin >> A >> B;
        if (1 <= A && A <= N && 1 <= B && B <= M) blocked[A][B] = 1;
    }

    vector<vector<char>> vis(N + 1, vector<char>(M + 1, 0));
    queue<pair<int,int>> q;
    if (!blocked[X][Y]) {
        vis[X][Y] = 1;
        q.push({X, Y});
    }

    long long cnt = 0;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        cnt++;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (blocked[nx][ny]) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    cout << cnt << "\n";
    return 0;
}