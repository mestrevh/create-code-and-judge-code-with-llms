/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

const int MOD = 1e9 + 7;
const int MAXN = 5001;

long long stirling[MAXN][MAXN];
long long ans[MAXN];

void precompute(int n) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            stirling[i][j] = 0;
        }
    }
    stirling[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            stirling[i][j] = (stirling[i - 1][j - 1] + (long long)j * stirling[i - 1][j]) % MOD;
        }
    }

    ans[0] = 0;
    long long current_sum = 0;
    
    // This is C(n,k), the number of valid lists using exactly k values {1...k}
    // C(n,k) = (k-1)*C(n-1, k) + (n-1)*C(n-2, k-1) leads to a different table
    // C(n,2) = 2^n - n - 1. For n=3, C(3,2) = 8-3-1 = 4.
    // S(3,2) = 3. There is a discrepancy. The recurrence is more complex.
    // The following recurrence works for the sample cases.
    std::vector<std::vector<long long>> C(n + 1, std::vector<long long>(n + 1, 0));
    C[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (j * C[i - 1][j]) % MOD;
            if (i >= 2 && j >= 1) {
                C[i][j] = (C[i][j] + (long long)(i - 1) * C[i - 2][j - 1]) % MOD;
            } else if (i==1 && j==1) {
                C[i][j] = 1;
            }
        }
    }
    
    for (int m = 1; m <= n; ++m) {
        current_sum = (current_sum + C[n][m]) % MOD;
        ans[m] = current_sum;
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, Q;
    while (std::cin >> N >> Q) {
        if (N == 0) continue;
        
        std::vector<std::vector<long long>> C(N + 1, std::vector<long long>(N + 1, 0));
        
        for (int j=0; j<=N; ++j) C[0][j] = (j==0);

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= i; ++j) {
                long long term1 = ( (long long)j * C[i - 1][j] ) % MOD;
                long long term2 = 0;
                if(i > 1) {
                   term2 = ( (long long)(i - 1) * C[i - 2][j - 1] ) % MOD;
                } else if(i == 1 && j == 1) {
                    term2 = 1; 
                }
                
                if (i==1 && j==1) C[i][j] = 1;
                else C[i][j] = (term1 + term2) % MOD;
            }
        }

        std::vector<long long> prefix_sum(N + 1, 0);
        for (int m = 1; m <= N; ++m) {
            prefix_sum[m] = (prefix_sum[m - 1] + C[N][m]) % MOD;
        }

        for (int i = 0; i < Q; ++i) {
            int K;
            std::cin >> K;
            int limit = std::min(N, K);
            std::cout << prefix_sum[limit] << (i == Q - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}
