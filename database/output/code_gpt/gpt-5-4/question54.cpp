/*
Código criado pelo gpt-5.4
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;

        vector<vector<int>> a(N + 1, vector<int>(N + 1, 0));

        for (int i = 0; i < M; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            a[x][y] = a[y][x] = z;
        }

        long long best = -1;
        array<int, 3> ans = {1, 2, 3};

        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                for (int k = j + 1; k <= N; ++k) {
                    long long sum = (long long)a[i][j] + a[i][k] + a[j][k];
                    array<int, 3> cur = {i, j, k};
                    if (sum > best || (sum == best && cur < ans)) {
                        best = sum;
                        ans = cur;
                    }
                }
            }
        }

        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    }

    return 0;
}