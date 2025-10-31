/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int caso = 1; caso <= T; caso++) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        vector<vector<bool>> dp(N + 1, vector<bool>(100001, false));
        dp[0][0] = true;
        
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= 100000; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= A[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - A[i - 1]];
                }
            }
        }
        
        cout << "caso " << caso << ":";
        for (int i = 0; i < M; i++) {
            int X, K;
            cin >> X >> K;
            cout << ' ' << (K <= 100000 && dp[X][K] ? 1 : 0);
        }
        cout << endl;
    }
    return 0;
}
