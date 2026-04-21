/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M, X;
    if (!(cin >> N)) return 0;
    cin >> M >> X;

    vector<vector<string>> a(N, vector<string>(M));
    for (long long i = 0; i < N; i++) {
        for (long long j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    long long idx = 0;
    if (N != 0) idx = X % N;

    vector<string> ans = a[idx];

    for (long long j = 0; j < M; j++) {
        string s;
        if (j < (long long)ans.size() && !ans[j].empty()) s = ans[j];
        else s = "Qualquer";
        if (j) cout << ' ';
        cout << s;
    }

    return 0;
}