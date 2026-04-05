/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long B, E, K, C, F;
    if (!(cin >> B >> E >> K >> C >> F)) return 0;

    auto ceil_div = [&](long long a, long long b) -> long long {
        if (b < 0) a = -a, b = -b;
        if (a >= 0) return (a + b - 1) / b;
        return a / b;
    };

    long long T = E - B;
    long long step = K + 1;
    long long M = T / step;
    long long rem = T % step;
    long long N = M + (rem > 0 ? 1 : 0);

    vector<long long> seqStart(F), seqStep(F);
    for (long long i = 0; i < F; i++) {
        seqStart[i] = B + (K + 1) * (i % F);
        seqStep[i] = F * (K + 1);
    }

    vector<long long> extra(F, 0);
    for (long long i = 0; i < F; i++) {
        if (i < (N % F)) extra[i] = 1;
    }

    vector<long long> start(F), endv(F), curCount(F);
    for (long long w = 0; w < F; w++) {
        long long cnt = N / F + extra[w];
        long long first = seqStart[w];
        long long last = first + (cnt - 1) * seqStep[w];
        start[w] = first;
        endv[w] = last;
        curCount[w] = cnt;
    }

    for (long long w = 0; w < F; w++) {
        long long cnt = curCount[w];
        long long first = start[w];
        long long last = endv[w];
        if (cnt == 0) continue;

        long long batchId = 0;
        for (long long j = 0; j < cnt; j += C) {
            long long take = min(C, cnt - j);
            long long segStart = first + j * seqStep[w];
            long long segEnd = segStart + (take - 1) * seqStep[w];
            batchId++;

            cout << "distribution " << batchId << " to worker " << w << ": ";
            cout << segStart << "-" << segEnd << ": ";
            for (long long t = 0; t < take; t++) {
                long long table = segStart + t * seqStep[w];
                cout << table << ", ";
            }
            cout << "\n";
        }
    }

    return 0;
}