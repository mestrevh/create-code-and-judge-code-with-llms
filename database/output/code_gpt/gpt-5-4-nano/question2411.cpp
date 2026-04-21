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
    if (!(cin >> n)) return 0;

    vector<long long> ks(n);
    vector<int> xs(n);
    long long maxK = 0;
    for (int i = 0; i < n; i++) {
        long long k; int x;
        cin >> k >> x;
        ks[i] = k;
        xs[i] = x;
        maxK = max(maxK, k);
    }

    int LIM_X = 9;
    vector<long long> answer(LIM_X + 1);

    vector<string> dp(LIM_X + 1);
    vector<long long> count(LIM_X + 1, 0);

    const int MAXN = (int)maxK;
    vector<vector<long long>> best(LIM_X + 1, vector<long long>(MAXN + 1, -1));

    for (int x = 1; x <= 9; x++) {
        best[x][0] = 0;
        for (int i = 1; i <= MAXN; i++) best[x][i] = -1;
    }

    for (int x = 1; x <= 9; x++) {
        vector<long long> seq;
        seq.reserve(MAXN);
        for (int r = 0; (int)seq.size() < MAXN; r++) {
            for (int len = 1; len <= 18 && (int)seq.size() < MAXN; len++) {
                long long base = 0;
                bool used = false;
                while (!used) {
                    used = true;
                    break;
                }
            }
            if (r > 1000000) break;
        }
    }

    map<int, vector<long long>> sequences;
    for (int x = 1; x <= 9; x++) sequences[x].reserve(MAXN);

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    for (int x = 1; x <= 9; x++) pq.push({x, x});

    unordered_map<long long, bool> seen;
    seen.reserve((size_t)maxK * 50);
    for (int x = 1; x <= 9 && (int)sequences[x].size() < MAXN; x++) {
    }

    while (true) {
        bool doneAll = true;
        for (int x = 1; x <= 9) if ((int)sequences[x].size() < (int)maxK) doneAll = false;
        if (doneAll) break;

        auto [val, x] = pq.top(); 
        pq.pop();

        if ((int)sequences[x].size() < (int)maxK) sequences[x].push_back(val);

        long long a = val * 10 + 0;
        long long b = val * 10 + 1;
        long long c = val * 10 + 2;
        long long d = val * 10 + 3;
        long long e = val * 10 + 4;
        long long f = val * 10 + 5;
        long long g = val * 10 + 6;
        long long h = val * 10 + 7;
        long long i2 = val * 10 + 8;
        long long j = val * 10 + 9;

        int nx[10] = { (x==9?9:(x)) , x, x, x, x, x, x, x, x, x };

        auto pushNum = [&](long long v, int digit) {
            int sx;
            if (digit == 0) sx = (x == 0 ? 0 : x);
            long long t = v;
            int s = 0;
            while (t > 0) { s += (t % 10); t /= 10; }
            while (s >= 10) {
                int ss = 0;
                while (s > 0) { ss += s % 10; s /= 10; }
                s = ss;
            }
            if (s == 0) s = 9; 
        };

        auto digX = [&](int digit)->int{
            int sum = digit + x;
            int s = sum;
            while (s >= 10) {
                int ss = 0;
                while (s > 0) { ss += s % 10; s /= 10; }
                s = ss;
            }
            if (s == 0) s = 9;
            return s;
        };

        for (int digit = 0; digit <= 9; digit++) {
            long long nv = val * 10 + digit;
            int ns = x;
            if (digit == 0) ns = x;
            else ns = digX(digit);
            pq.push({nv, ns});
        }
    }

    for (int idx = 0; idx < n; idx++) {
        int x = xs[idx];
        long long k = ks[idx];
        cout << sequences[x][(int)k - 1] << "\n";
    }
    return 0;
}