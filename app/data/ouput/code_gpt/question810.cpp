/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int M;
    cin >> M;
    for (int c = 0; c < M; ++c) {
        int N;
        cin >> N;
        vector<int> V(N);
        int total = 0;
        for (int i = 0; i < N; ++i) {
            cin >> V[i];
            total += V[i];
        }

        int half = total / 2;
        vector<bool> dp(half + 1, false);
        dp[0] = true;

        for (int v : V) {
            for (int j = half; j >= v; --j) {
                dp[j] = dp[j] || dp[j - v];
            }
        }

        int best = 0;
        for (int i = half; i >= 0; --i) {
            if (dp[i]) {
                best = i;
                break;
            }
        }

        int H0 = best, H1 = total - best;
        if (H0 > H1) swap(H0, H1);
        cout << "caso " << c << ": " << H0 << " " << H1 << endl;
    }
    return 0;
}
