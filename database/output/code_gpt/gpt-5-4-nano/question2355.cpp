/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    long long L;
    vector<pair<long long, string>> v;

    while (true) {
        if (!getline(cin, S)) break;
        if (S.size() == 0) continue;
        if (!(cin >> L)) break;
        v.push_back({L, S});
        string dummy;
        getline(cin, dummy);
    }

    sort(v.begin(), v.end(), [](const auto& a, const auto& b){
        return a.first < b.first;
    });

    for (auto &p : v) cout << p.second << "\n";
    return 0;
}