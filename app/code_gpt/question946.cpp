/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 200;
const int MAXM = 10;
const int MAXD = 20;

int dp[MAXN + 1][MAXD][MAXM + 1];

void clear_dp() {
    memset(dp, 0, sizeof(dp));
}

int main() {
    int N, Q, set_counter = 1;
    
    while (cin >> N >> Q, N || Q) {
        clear_dp();
        vector<int> numbers(N);
        
        for (int i = 0; i < N; i++) {
            cin >> numbers[i];
        }

        cout << "SET " << set_counter++ << ":\n";

        for (int query_index = 1; query_index <= Q; query_index++) {
            int D, M;
            cin >> D >> M;

            dp[0][0][0] = 1;

            for (int i = 0; i < N; i++) {
                for (int j = M; j > 0; j--) {
                    for (int k = 0; k < D; k++) {
                        dp[i + 1][(k + numbers[i]) % D][j] += dp[i][k][j - 1];
                    }
                }
                for (int k = 0; k < D; k++) {
                    dp[i + 1][k][0] += dp[i][k][0];
                }
            }

            cout << "QUERY " << query_index << ": " << dp[N][0][M] << "\n";
        }
    }

    return 0;
}
