/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N + 1);
        for (int i = 1; i <= N; i++) cin >> A[i];

        if (N <= 2) {
            cout << 1 << " " << N << "\n";
            continue;
        }

        long long bestStart = 1, bestEnd = 2;
        long long curStart = 1, curEnd = 2;
        long long dPrev = A[2] - A[1];

        for (int i = 3; i <= N; i++) {
            long long d = A[i] - A[i - 1];
            if (d == dPrev) {
                curEnd = i;
            } else {
                if (curEnd - curStart > bestEnd - bestStart) {
                    bestStart = curStart;
                    bestEnd = curEnd;
                }
                curStart = curEnd - 1;
                curEnd = i;
                dPrev = d;
            }
        }

        if (curEnd - curStart > bestEnd - bestStart) {
            bestStart = curStart;
            bestEnd = curEnd;
        }

        cout << bestStart << " " << bestEnd << "\n";
    }
    return 0;
}