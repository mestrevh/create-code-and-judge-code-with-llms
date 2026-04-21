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
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<long long> sorted = a;
    sort(sorted.begin(), sorted.end());

    vector<pair<long long,int>> ans;
    for (int i = 0; i < N; i++) {
        if (a[i] == sorted[i]) ans.push_back({a[i], i + 1});
    }

    cout << ans.size() << "\n";
    for (auto &p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}