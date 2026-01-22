/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        vector<vector<int>> ent(N + 1, vector<int>(N + 1, 0));
        for (int i = 0; i < M; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            ent[x][y] = z;
            ent[y][x] = z;
        }
        int maxsum = -1;
        int res[3];
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                for (int k = j + 1; k <= N; ++k) {
                    int sum = ent[i][j] + ent[j][k] + ent[k][i];
                    if (sum > maxsum) {
                        maxsum = sum;
                        res[0] = i;
                        res[1] = j;
                        res[2] = k;
                    }
                }
            }
        }
        cout << res[0] << " " << res[1] << " " << res[2] << endl;
    }
    return 0;
}
