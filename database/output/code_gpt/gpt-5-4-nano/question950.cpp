/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    if (!(cin >> S)) return 0;

    int n = (int)S.size();

    vector<string> dp(n + 1);
    dp[0] = "";

    for (int i = 1; i <= n; i++) {
        int pos = n - i + 1;
        char c = S[pos - 1];
        if (c == '*') dp[i] = "(" + to_string(pos) + dp[i - 1] + ")";
        else dp[i] = to_string(pos) + dp[i - 1];
    }

    cout << dp[n] << "\n";
    return 0;
}