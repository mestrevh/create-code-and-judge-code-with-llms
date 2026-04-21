/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    long long X;
    if (!(cin >> N >> M >> X)) return 0;

    vector<int> cnt(M, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            long long v;
            cin >> v;
            if (v == X) cnt[j]++;
        }
    }

    int A = 0;
    for (int j = 0; j < M; j++) A = max(A, cnt[j]);

    for (int j = 0; j < M; j++) {
        if (j) cout << ' ';
        cout << cnt[j];
    }
    cout << "\n\n";

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < M; j++) {
            int val = (i < A - cnt[j]) ? 0 : 1;
            if (j) cout << ' ';
            cout << val;
        }
        cout << "\n";
    }

    return 0;
}