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
    int tc = 1;
    while ( (cin >> N) ) {
        if (N == 0) break;
        vector<long long> pref(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            long long X, Y;
            cin >> X >> Y;
            long long a = X - Y;
            pref[i] = pref[i - 1] + a;
        }

        long long best = LLONG_MIN;
        int bestI = -1, bestJ = -1;
        long long minPref = pref[0];
        int minPos = 0;

        for (int j = 1; j <= N; j++) {
            long long cur = pref[j] - minPref;
            if (cur > best) {
                best = cur;
                bestI = minPos + 1;
                bestJ = j;
            } else if (cur == best) {
                int lenBest = bestJ - bestI;
                int lenCur = j - (minPos + 1);
                if (lenCur > lenBest) {
                    bestI = minPos + 1;
                    bestJ = j;
                }
            }

            if (pref[j] < minPref) {
                minPref = pref[j];
                minPos = j;
            } else if (pref[j] == minPref) {
                if (j > minPos) minPos = j;
            }
        }

        cout << "Teste " << tc++ << "\n";
        if (best <= 0) {
            cout << "nenhum\n\n";
        } else {
            cout << bestI << " " << bestJ << "\n\n";
        }
    }
    return 0;
}