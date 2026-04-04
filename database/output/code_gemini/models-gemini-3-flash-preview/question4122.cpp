/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int freq[100005];
int cnt[200005];
long long ans_cache[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a >= 0 && a <= 100000) {
            freq[a]++;
        }
    }

    vector<int> d_val;
    vector<int> d_freq;
    d_val.reserve(100000);
    d_freq.reserve(100000);
    for (int i = 0; i <= 100000; i++) {
        if (freq[i] > 0) {
            d_val.push_back(i);
            d_freq.push_back(freq[i]);
        }
    }

    for (int i = 0; i <= 200000; i++) {
        ans_cache[i] = -1;
    }

    int Q;
    if (!(cin >> Q)) return 0;

    vector<int> active_rs;
    active_rs.reserve(100000);

    while (Q--) {
        int K;
        cin >> K;

        if (K > 200000) {
            cout << "0\n";
            continue;
        }

        if (ans_cache[K] != -1) {
            cout << ans_cache[K] << "\n";
            continue;
        }

        if (K == 1) {
            long long res = (long long)N * (N - 1) / 2;
            ans_cache[K] = res;
            cout << res << "\n";
            continue;
        }

        active_rs.clear();
        for (size_t i = 0; i < d_val.size(); i++) {
            int r = d_val[i] % K;
            if (cnt[r] == 0) {
                active_rs.push_back(r);
            }
            cnt[r] += d_freq[i];
        }

        long long res = (long long)cnt[0] * (cnt[0] - 1) / 2;
        for (int r : active_rs) {
            if (r == 0) continue;
            int r2 = K - r;
            if (r == r2) {
                res += (long long)cnt[r] * (cnt[r] - 1) / 2;
            } else if (r < r2) {
                // r2 is (K-r), so r2 < K is guaranteed as r > 0.
                // Multiplication should be long long.
                res += (long long)cnt[r] * (long long)cnt[r2];
            }
        }

        for (int r : active_rs) {
            cnt[r] = 0;
        }

        ans_cache[K] = res;
        cout << res << "\n";
    }

    return 0;
}