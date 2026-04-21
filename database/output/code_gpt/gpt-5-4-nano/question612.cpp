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
    if (!(cin >> N >> M)) return 0;

    vector<long long> B(M);
    vector<array<long long, 5>> otherSum(M);
    vector<array<int, 5>> cnts(M);

    const vector<long long> vals = {1, 10, 100, 1000, 10000};

    for (int r = 0; r < M; r++) {
        long long b;
        cin >> b;
        B[r] = b;
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            long long c;
            cin >> c;
            sum += c;
        }
        for (int j = 0; j < 5; j++) {
            otherSum[r][j] = sum - vals[j];
        }
        for (int j = 0; j < 5; j++) cnts[r][j] = 0;
    }

    long long total = 0;
    for (int r = 0; r < M; r++) {
        long long best = 0;
        for (int j = 0; j < 5; j++) {
            if (otherSum[r][j] + vals[j] <= B[r]) best = max(best, vals[j]);
        }
        total += best;
    }

    cout << total << "\n";
    return 0;
}