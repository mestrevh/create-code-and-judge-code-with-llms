/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<pair<long long,int>> totals;
    totals.reserve(N);

    for (int i = 1; i <= N; i++) {
        long long sum = 0;
        for (int j = 0; j < M; j++) {
            long long x;
            cin >> x;
            sum += x;
        }
        totals.push_back({sum, i});
    }

    nth_element(totals.begin(), totals.begin() + 3, totals.end(),
                [](const auto& a, const auto& b){ return a.first < b.first; });

    sort(totals.begin(), totals.begin() + 3,
         [](const auto& a, const auto& b){ return a.first < b.first; });

    cout << totals[0].second << "\n" << totals[1].second << "\n" << totals[2].second << "\n";
    return 0;
}