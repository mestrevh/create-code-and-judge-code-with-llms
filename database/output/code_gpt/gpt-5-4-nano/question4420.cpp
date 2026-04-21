/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static long long fibLimit(long long a, long long b, long long X) {
    if (X == 0) return 0;
    if (b > X && a > X) return 2;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X;
    int N;
    if (!(cin >> X >> N)) return 0;

    long long bestDist = LLONG_MAX;
    long long bestA = 0, bestB = 0;
    int bestIdx = -1;
    long long bestMinute = 0;

    for (int idx = 1; idx <= N; idx++) {
        long long a, b;
        cin >> a >> b;

        vector<long long> f;
        f.reserve(100);

        f.push_back(a); 
        f.push_back(b); 

        long long term1 = a, term2 = b;

        auto digitSum = [&](long long v) -> long long {
            if (v < 0) v = -v;
            long long s = 0;
            while (v > 0) { s += v % 10; v /= 10; }
            return s;
        };

        auto eval = [&](long long val, long long minute) {
            long long dist = llabs(val - X);
            if (dist < bestDist || (dist == bestDist && idx > bestIdx)) {
                bestDist = dist;
                bestA = a;
                bestB = b;
                bestIdx = idx;
                bestMinute = minute;
            } else if (dist == bestDist && idx == bestIdx) {
                if (minute < bestMinute) bestMinute = minute;
            }
        };

        eval(f[0], 1);
        if (bestIdx == -1) {
            bestIdx = idx;
            bestDist = llabs(f[0] - X);
            bestMinute = 1;
            bestA = a; bestB = b;
        }

        if (N == 0) continue;

        long long minute = 2;
        eval(f[1], 2);

        long long limit = max( (long long)1, llabs(X) ) + 1000000LL;

        while (true) {
            __int128 nxt128 = (__int128)term1 + (__int128)term2;
            if (nxt128 > LLONG_MAX) break;
            long long nxt = (long long)nxt128;
            minute++;
            if (nxt > limit && nxt - X > bestDist && minute > 3) {
                break;
            }
            eval(nxt, minute);
            term1 = term2;
            term2 = nxt;
            if (minute > 1000) break;
        }
    }

    cin.clear();

    int idx;
    long long a, b;
    cin.seekg(0, ios::beg);
    long long X2; int N2;
    cin >> X2 >> N2;

    vector<pair<long long,long long>> channels(N2+1);
    for (int i = 1; i <= N2; i++) cin >> channels[i].first >> channels[i].second;

    idx = bestIdx;
    a = channels[idx].first;
    b = channels[idx].second;

    auto digitSum = [&](long long v) -> long long {
        if (v < 0) v = -v;
        long long s = 0;
        while (v > 0) { s += v % 10; v /= 10; }
        return s;
    };

    long long term;
    if (bestMinute == 1) term = a;
    else if (bestMinute == 2) term = b;
    else {
        long long x1 = a, x2 = b;
        for (long long m = 3; m <= bestMinute; m++) {
            long long nxt = x1 + x2;
            x1 = x2;
            x2 = nxt;
        }
        term = (bestMinute == 2 ? b : (bestMinute == 1 ? a : (x2)));
        if (bestMinute >= 3) term = x2;
    }

    bool vip = (digitSum(term) > 10);

    if (vip) {
        cout << "Xupenio, para ir ao lulupalooza vc deve entrar no canal " << idx
             << " e sera chamado mais ou menos no minuto " << bestMinute
             << ", mas o ingresso VIP garantido!!!\n";
    } else {
        cout << "Xupenio, para ir ao lulupalooza vc deve entrar no canal " << idx
             << " e sera chamado mais ou menos no minuto " << bestMinute
             << ", mas o ingresso VIP não vai rolar :(\n";
    }

    return 0;
}