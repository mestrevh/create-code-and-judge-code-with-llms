/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, N;
    if (!(cin >> C >> N)) return 0;

    unordered_map<long long, long long> installed;
    installed.reserve(C * 2);

    for (int i = 0; i < C; i++) {
        long long Pc, Vc;
        cin >> Pc >> Vc;
        installed[Pc] = Vc;
    }

    unordered_map<long long, long long> latest;
    latest.reserve(N * 2);

    for (int i = 0; i < N; i++) {
        long long Pn, Vn;
        cin >> Pn >> Vn;
        auto it = latest.find(Pn);
        if (it == latest.end() || Vn > it->second) latest[Pn] = Vn;
    }

    vector<pair<long long, long long>> toInstall;
    toInstall.reserve(latest.size());

    for (auto &kv : latest) {
        long long p = kv.first;
        long long v = kv.second;
        auto it = installed.find(p);
        if (it == installed.end() || v > it->second) toInstall.push_back({p, v});
    }

    sort(toInstall.begin(), toInstall.end());
    for (auto &pr : toInstall) {
        cout << pr.first << " " << pr.second << "\n";
    }
    return 0;
}