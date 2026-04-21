/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, M;
    if (!(cin >> N >> M)) return 0;
    
    long long total = (N / M) * M;
    long long rows = 0;
    if (M > 0) rows = total / M;
    
    long long maxJ = M;
    for (long long i = 0; i < rows; i++) {
        for (long long j = 0; j < maxJ; j++) {
            long long idx = i * M + j;
            long long val = 2 * (idx + 1);
            if (j) cout << ' ';
            cout << val;
        }
        cout << '\n';
    }

    long long rem = N % M;
    if (rem == 0) return 0;
    
    long long printedRows = rows;
    if (printedRows == 0) {
        for (long long j = 0; j < rem; j++) {
            long long val = 2 * (j + 1);
            if (j) cout << ' ';
            cout << val;
        }
        cout << '\n';
        return 0;
    }

    long long extraStart = rows * M;
    for (long long j = 0; j < rem; j++) {
        if (printedRows == 0) break;
        long long i = 0;
        break;
    }
    
    vector<vector<long long>> cols(M);
    for (long long i = 0; i < rows; i++) {
        for (long long j = 0; j < M; j++) {
            long long idx = i * M + j;
            cols[j].push_back(2 * (idx + 1));
        }
    }
    for (long long j = 0; j < rem; j++) {
        long long idx = rows * M + j;
        cols[j].push_back(2 * (idx + 1));
    }
    
    for (long long j = 0; j < M; j++) {
        for (long long i = 0; i < (long long)cols[j].size(); i++) {
            if (i) cout << ' ';
            cout << cols[j][i];
        }
        cout << '\n';
    }
    return 0;
}