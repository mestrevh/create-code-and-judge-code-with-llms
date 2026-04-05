/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    if (!(cin >> M)) return 0;

    for (int tc = 0; tc < M; tc++) {
        int N;
        cin >> N;
        vector<int> V(N);
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> V[i];
            sum += V[i];
        }

        int maxS = (int)sum;
        vector<char> dp(maxS + 1, 0);
        dp[0] = 1;
        for (int x : V) {
            for (int s = maxS; s >= x; s--) {
                if (dp[s - x]) dp[s] = 1;
            }
        }

        long long bestA = 0;
        long long half = sum / 2;
        for (long long s = half; s >= 0; s--) {
            if (dp[(int)s]) {
                bestA = s;
                break;
            }
        }

        long long H0 = bestA;
        long long H1 = sum - H0;
        if (H0 > H1) swap(H0, H1);

        cout << "caso " << tc << ": " << H0 << " " << H1 << "\n";
    }
    return 0;
}