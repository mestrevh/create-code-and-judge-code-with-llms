/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
long long p[305];
long long memo[305][305];

long long solve(int L, int R) {
    if (L > R) {
        return 0;
    }
    if (memo[L][R] != -1) {
        return memo[L][R];
    }
    
    // Total bottles = N
    // Current range length = R - L + 1
    // Bottles sold = N - (R - L + 1)
    // Current year = bottles sold + 1 = N - R + L
    int year = N - (R - L);
    
    long long sellLeft = p[L] * year + solve(L + 1, R);
    long long sellRight = p[R] * year + solve(L, R - 1);
    
    return memo[L][R] = max(sellLeft, sellRight);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (cin >> N) {
        for (int i = 0; i < N; ++i) {
            cin >> p[i];
        }
        
        if (N == 0) {
            cout << 0 << "\n";
            continue;
        }
        
        memset(memo, -1, sizeof(memo));
        cout << solve(0, N - 1) << "\n";
    }
    
    return 0;
}