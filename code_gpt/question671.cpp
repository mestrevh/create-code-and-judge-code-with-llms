/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

vector<long long> precompute(int maxN) {
    vector<long long> dp(maxN + 1);
    dp[0] = 1; // base case
    dp[1] = 0; // no configurations for 1 person
    dp[2] = 1; // only one configuration for 2 people

    for (int i = 3; i <= maxN; ++i) {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
    }

    return dp;
}

int main() {
    int T;
    cin >> T;
    vector<int> cases(T);
    int maxN = 0;

    for (int i = 0; i < T; ++i) {
        cin >> cases[i];
        if (cases[i] > maxN) {
            maxN = cases[i];
        }
    }

    vector<long long> configurations = precompute(maxN);

    for (int i = 0; i < T; ++i) {
        cout << configurations[cases[i]] << endl;
    }

    return 0;
}
