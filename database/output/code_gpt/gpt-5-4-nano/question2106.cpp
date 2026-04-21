/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> nextPos(n);
    for (int i = 0; i < n; i++) {
        int to = (i + (int)a[i]) % n;
        if (to < 0) to += n;
        nextPos[i] = to;
    }

    long long bestSum = -1;
    int bestStart = 0;

    int LOG = 0;
    while ((1LL << LOG) <= k) LOG++;
    vector<vector<int>> up(LOG, vector<int>(n));
    vector<vector<long long>> add(LOG, vector<long long>(n));

    for (int i = 0; i < n; i++) {
        up[0][i] = nextPos[i];
        add[0][i] = a[nextPos[i]] % n == 0 ? n : a[nextPos[i]] % n;
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            int mid = up[j-1][i];
            up[j][i] = up[j-1][mid];
            add[j][i] = add[j-1][i] + add[j-1][mid];
        }
    }

    for (int start = 0; start < n; start++) {
        long long sum = 0;
        int pos = start;
        long long steps = k;
        int bit = 0;
        while (steps > 0) {
            if (steps & 1LL) {
                sum += add[bit][pos];
                pos = up[bit][pos];
            }
            steps >>= 1LL;
            bit++;
        }
        sum += n;
        if (sum > bestSum) {
            bestSum = sum;
            bestStart = start;
        }
    }

    cout << bestStart << " " << bestSum;
    return 0;
}