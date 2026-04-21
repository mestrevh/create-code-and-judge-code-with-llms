/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<long long> s;
    s.reserve(64);

    for (int i = 0; i < 45; i++) {
        long long x;
        if (!(cin >> x)) return 0;
        s.insert(x);
    }

    vector<long long> inter;
    inter.reserve(45);

    unordered_set<long long> seen;
    for (int i = 0; i < 30; i++) {
        long long x;
        cin >> x;
        if (s.find(x) != s.end()) seen.insert(x);
    }

    bool first = true;
    for (int i = 0; i < 45; i++) {
        cin.clear();
    }

    cin.clear();
    cin.seekg(0, ios::beg);

    for (int i = 0; i < 45; i++) {
        long long x;
        cin >> x;
        if (seen.find(x) != seen.end()) {
            if (!first) cout << ' ';
            cout << x;
            first = false;
        }
    }

    cout << ' ' << "\n";
    return 0;
}