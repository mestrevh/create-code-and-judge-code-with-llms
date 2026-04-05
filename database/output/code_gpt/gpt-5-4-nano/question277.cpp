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
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        if (!(cin >> a[i])) return 0;
        if (a[i] <= 0) {
            cout << -1 << "\n";
            return 0;
        }
    }

    if (N < 3) return 0;

    vector<long long> sums;
    sums.reserve((size_t)N * (N - 1) * (N - 2) / 6);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                sums.push_back(a[i] + a[j] + a[k]);
            }
        }
    }

    sort(sums.begin(), sums.end());

    auto countInSums = [&](long long s) -> int {
        auto range = equal_range(sums.begin(), sums.end(), s);
        return (int)(range.second - range.first);
    };

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                long long s = a[i] + a[j] + a[k];
                if (countInSums(s) == 1) {
                    cout << "{" << a[i] << "," << a[j] << "," << a[k] << "} = " << s << "\n";
                }
            }
        }
    }

    return 0;
}