/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q, D;
    if (!(cin >> Q >> D)) return 0;

    if (Q > 10) Q = 10;
    
    long long dp[11][61];
    for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= 60; ++j) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (int i = 1; i <= Q; ++i) {
        for (int j = 0; j <= 60; ++j) {
            if (dp[i - 1][j] > 0) {
                for (int k = 1; k <= 6; ++k) {
                    if (j + k <= 60) {
                        dp[i][j + k] += dp[i - 1][j];
                    }
                }
            }
        }
    }

    long long count = 0;
    for (int j = D; j <= 60; ++j) {
        count += dp[Q][j];
    }

    cout << count << endl;

    return 0;
}