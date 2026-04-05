/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int G, P;
    while ( (cin >> G >> P) ) {
        if (G == 0 && P == 0) break;

        vector<vector<int>> pos(G, vector<int>(P));
        for (int r = 0; r < G; r++) {
            for (int i = 0; i < P; i++) cin >> pos[r][i];
        }

        int S;
        cin >> S;
        vector<long long> winners;
        for (int si = 0; si < S; si++) {
            int K;
            cin >> K;
            vector<long long> points(K + 1, 0);
            for (int j = 0; j < K; j++) cin >> points[j + 1];

            vector<long long> score(P + 1, 0);
            for (int r = 0; r < G; r++) {
                for (int i = 1; i <= P; i++) {
                    int arrivalRank = pos[r][i - 1];
                    if (arrivalRank <= K) score[i] += points[arrivalRank];
                }
            }

            long long best = -1;
            for (int i = 1; i <= P; i++) best = max(best, score[i]);

            bool first = true;
            for (int i = 1; i <= P; i++) {
                if (score[i] == best) {
                    if (!first) cout << ' ';
                    cout << i;
                    first = false;
                }
            }
            cout << '\n';
        }
    }
    return 0;
}