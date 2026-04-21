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

    vector<long long> result;
    unordered_set<long long> seen;
    seen.reserve(200000);
    seen.max_load_factor(0.7f);

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (seen.insert(x).second) result.push_back(x);
    }

    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        long long x;
        cin >> x;
        if (seen.insert(x).second) result.push_back(x);
    }

    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        if (i) cout << ", ";
        cout << result[i];
    }
    cout << "]";
    return 0;
}