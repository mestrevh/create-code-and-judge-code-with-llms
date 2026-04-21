/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    vector<int> Q;
    Q.reserve(1000005);
    int freq[1005];

    for (int t = 1; t <= T; ++t) {
        int N, M, K;
        if (!(cin >> N >> M >> K)) break;

        for (int i = 0; i <= 1000; ++i) freq[i] = 0;
        for (int i = 0; i < N; ++i) {
            int p;
            cin >> p;
            if (p >= 0 && p <= 1000) freq[p]++;
        }

        Q.resize(M);
        for (int i = 0; i < M; ++i) {
            cin >> Q[i];
        }

        long long S = 0;
        int count_drinks = 0;
        for (int v = 1; v <= 1000; ++v) {
            if (freq[v] > 0) {
                int take = min(freq[v], K - count_drinks);
                S += (long long)take * v;
                count_drinks += take;
                if (count_drinks == K) break;
            }
        }

        int min_len = -1;
        long long cur_sum = 0;
        int left = 0;
        for (int right = 0; right < M; ++right) {
            cur_sum += (long long)Q[right];
            while (cur_sum >= S) {
                int len = right - left + 1;
                if (min_len == -1 || len < min_len) {
                    min_len = len;
                }
                cur_sum -= (long long)Q[left];
                left++;
            }
        }

        cout << "Caso #" << t << ": " << min_len << "\n";
    }

    return 0;
}