/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    unordered_map<long long, long long> cnt1, cnt2;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt1[a[i]]++;
    }

    int n2;
    cin >> n2;
    vector<long long> b(n2);
    for (int i = 0; i < n2; i++) {
        cin >> b[i];
        cnt2[b[i]]++;
    }

    vector<long long> repeated;
    vector<long long> uniqueNoRepeated;
    vector<long long> allNoRepeated;

    set<long long> allValues;
    for (auto &p : cnt1) allValues.insert(p.first);
    for (auto &p : cnt2) allValues.insert(p.first);

    for (auto v : allValues) {
        long long total = 0;
        auto it1 = cnt1.find(v);
        if (it1 != cnt1.end()) total += it1->second;
        auto it2 = cnt2.find(v);
        if (it2 != cnt2.end()) total += it2->second;
        if (total >= 2) repeated.push_back(v);
    }

    for (auto v : allValues) {
        if (cnt1.find(v) != cnt1.end() || cnt2.find(v) != cnt2.end()) uniqueNoRepeated.push_back(v);
    }

    vector<long long> repeatedSet(repeated.begin(), repeated.end());
    sort(repeatedSet.begin(), repeatedSet.end());

    vector<long long> repeatedFlags(allValues.size());
    unordered_set<long long> rep(repeated.begin(), repeated.end());

    vector<long long> withoutRepeated;
    for (auto v : allValues) {
        if (rep.find(v) == rep.end()) withoutRepeated.push_back(v);
    }

    auto printVec = [&](const vector<long long>& v) {
        cout << "[";
        for (size_t i = 0; i < v.size(); i++) {
            if (i) cout << ", ";
            cout << v[i];
        }
        cout << "]";
    };

    printVec(repeated);
    cout << "\n";
    sort(uniqueNoRepeated.begin(), uniqueNoRepeated.end());
    printVec(uniqueNoRepeated);
    cout << "\n";
    printVec(withoutRepeated);
    return 0;
}