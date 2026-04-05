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
    vector<pair<long long,long long>> a(N);
    for (int i = 0; i < N; i++) cin >> a[i].first >> a[i].second;

    long long rem = N - 1;
    long long bestRisk = LLONG_MAX, bestDiff = LLONG_MAX;
    int bestIdx = -1;

    for (int i = 0; i < N; i++) {
        long long diff = a[i].first;
        long long risk = a[i].second;
        if (diff + risk < rem) {
            cout << diff << " " << risk;
            return 0;
        }
        if (risk < bestRisk || (risk == bestRisk && diff < bestDiff)) {
            bestRisk = risk;
            bestDiff = diff;
            bestIdx = i;
        }
        if (rem > 0) rem--;
    }

    cout << a[bestIdx].first << " " << a[bestIdx].second;
    return 0;
}