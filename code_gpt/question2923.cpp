/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];

    int maxTri = 0;

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            if (mat[i][j] == 1) {
                dp[i][j] = 1;
                int height = 0;
                while (i - height >= 0 && j - height >= 0 && j + height < n) {
                    if (mat[i - height][j - height] == 1 && mat[i - height][j + height] == 1) {
                        dp[i][j]++;
                        height++;
                    } else {
                        break;
                    }
                }
                maxTri = max(maxTri, dp[i][j] * (dp[i][j] + 1) / 2);
            }
        }
    }
    
    cout << maxTri * 2 << endl;
    return 0;
}
