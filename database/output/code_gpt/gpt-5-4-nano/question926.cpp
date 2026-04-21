/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long P;
    int S;
    if (!(cin >> P >> S)) return 0;

    vector<pair<long long,long long>> segs;
    segs.reserve(S);
    for (int i = 0; i < S; i++) {
        long long U, V;
        cin >> U >> V;
        segs.push_back({U, V});
    }

    sort(segs.begin(), segs.end(), [](const auto& a, const auto& b){
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    vector<pair<long long,long long>> merged;
    for (const auto& [l, r] : segs) {
        if (merged.empty() || l > merged.back().second) {
            merged.push_back({l, r});
        } else {
            merged.back().second = max(merged.back().second, r);
        }
    }

    for (const auto& [l, r] : merged) {
        cout << l << ' ' << r << "\n";
    }
    cout << "\n";
    return 0;
}