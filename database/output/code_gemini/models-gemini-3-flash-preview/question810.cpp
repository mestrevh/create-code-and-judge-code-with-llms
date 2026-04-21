/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <bitset>

using namespace std;

static bitset<1100000> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    if (!(cin >> M)) return 0;

    for (int c = 0; c < M; ++c) {
        int N;
        if (!(cin >> N)) break;

        long long total_sum = 0;
        dp.reset();
        dp[0] = 1;

        for (int i = 0; i < N; ++i) {
            int v;
            cin >> v;
            total_sum += v;
            if (v < 1100000) {
                dp |= (dp << v);
            }
        }

        int h0 = 0;
        long long target = total_sum / 2;
        if (target >= 1100000) target = 1100000 - 1;

        for (int i = (int)target; i >= 0; --i) {
            if (dp[i]) {
                h0 = i;
                break;
            }
        }

        cout << "caso " << c << ": " << h0 << " " << total_sum - h0 << "\n";
    }

    return 0;
}