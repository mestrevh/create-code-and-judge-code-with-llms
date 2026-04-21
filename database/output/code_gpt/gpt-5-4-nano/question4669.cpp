/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<char,char>> pairs;
    for (int i = 0; i < 3; i++) {
        char x, y;
        if (!(cin >> x >> y)) return 0;
        pairs.push_back({x, y});
    }

    set<char> A, B;
    for (auto &p : pairs) {
        A.insert(p.first);
        B.insert(p.second);
    }

    bool disjoint = true;
    for (char a : A) {
        if (B.count(a)) { disjoint = false; break; }
    }

    if (disjoint) {
        cout << "A ^ B void";
        return 0;
    }

    bool funcTotal = true;
    bool relation = false;

    map<char, set<char>> mp;
    for (auto &p : pairs) mp[p.first].insert(p.second);

    for (char a : A) {
        if (mp[a].empty()) funcTotal = false;
        if ((int)mp[a].size() > 1) relation = true;
    }

    if (A.size() < 3) funcTotal = false;

    if (relation) cout << "A <-> B";
    else cout << (funcTotal ? "A --> B" : "A +-> B");

    return 0;
}