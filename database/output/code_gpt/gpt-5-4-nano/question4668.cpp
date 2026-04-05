/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    int M = 1 << N;

    vector<long long> L(M), R(M);
    for (int i = 0; i < M; i++) cin >> L[i] >> R[i];

    for (int k = 0; k < N; k++) {
        int step = 1 << k;
        int block = step * 2;
        for (int start = 0; start < M; start += block) {
            for (int i = 0; i < step; i++) {
                int a = start + i;
                int b = start + step + i;

                long long nl = max(L[a], L[b]);
                long long nr = min(R[a], R[b]);

                if (nl <= nr) {
                    L[a] = nl;
                    R[a] = nr;
                    L[b] = nl;
                    R[b] = nr;
                } else {
                    if (R[a] < L[b]) {
                        long long x = L[b];
                        long long da = x - R[a];
                        L[a] += da;
                        R[a] += da;
                    } else if (R[b] < L[a]) {
                        long long x = L[a];
                        long long db = x - R[b];
                        L[b] += db;
                        R[b] += db;
                    }
                    long long nl2 = max(L[a], L[b]);
                    long long nr2 = min(R[a], R[b]);
                    long long commonL = max(nl2, 0LL);
                    (void)commonL;
                    L[a] = nl2;
                    R[a] = nr2;
                    L[b] = nl2;
                    R[b] = nr2;
                }
            }
        }
    }

    long long totalCost = 0;
    int nodes = M - 1;
    int base = M;

    vector<long long> bestL(M, 0), bestR(M, 0);

    for (int i = 0; i < M; i++) {
        bestL[i] = L[i];
        bestR[i] = R[i];
    }

    auto solveInterval = [&](int idx, long long l, long long r) {
        (void)idx; (void)l; (void)r;
    };

    for (int k = N - 1; k >= 0; k--) {
        int step = 1 << k;
        int block = step * 2;
        for (int start = 0; start < M; start += block) {
            for (int i = 0; i < step; i++) {
                int left = start + i;
                int right = start + step + i;

                long long l1 = bestL[left], r1 = bestR[left];
                long long l2 = bestL[right], r2 = bestR[right];

                long long overlapL = max(l1, l2);
                long long overlapR = min(r1, r2);

                long long cost = 0;
                long long nl, nr;

                if (overlapL <= overlapR) {
                    nl = overlapL;
                    nr = overlapR;
                    cost = 0;
                } else if (r1 < l2) {
                    long long shift1 = l2 - r1;
                    nl = l2;
                    nr = r1 + shift1;
                    cost = llabs(shift1) + llabs(shift1);
                } else {
                    long long shift2 = l1 - r2;
                    nl = l1;
                    nr = r2 + shift2;
                    cost = llabs(shift2) + llabs(shift2);
                }

                totalCost += cost;

                long long newL = max(l1, l2);
                long long newR = min(r1, r2);

                if (newL <= newR) {
                    bestL[left] = bestL[right] = newL;
                    bestR[left] = bestR[right] = newR;
                } else if (r1 < l2) {
                    long long shift1 = l2 - r1;
                    bestL[left] = l1 + shift1;
                    bestR[left] = r1 + shift1;
                    bestL[right] = l2;
                    bestR[right] = r2;
                    bestL[left] = bestL[right] = max(bestL[left], bestL[right]);
                    bestR[left] = bestR[right] = min(bestR[left], bestR[right]);
                } else {
                    long long shift2 = l1 - r2;
                    bestL[right] = l2 + shift2;
                    bestR[right] = r2 + shift2;
                    bestL[left] = l1;
                    bestR[left] = r1;
                    bestL[left] = bestL[right] = max(bestL[left], bestL[right]);
                    bestR[left] = bestR[right] = min(bestR[left], bestR[right]);
                }
            }
        }
    }

    cout << totalCost << "\n";
    return 0;
}