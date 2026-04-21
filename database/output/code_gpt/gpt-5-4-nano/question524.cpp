/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line1, line2;
    if (!getline(cin, line1)) return 0;
    if (!getline(cin, line2)) return 0;

    auto parse = [&](const string& s) {
        vector<long long> v;
        string cur;
        for (char c : s) {
            if (c == '-' || isdigit((unsigned char)c)) cur.push_back(c);
            else {
                if (!cur.empty()) {
                    v.push_back(stoll(cur));
                    cur.clear();
                }
            }
        }
        if (!cur.empty()) v.push_back(stoll(cur));
        return v;
    };

    vector<long long> a = parse(line1);
    vector<long long> b = parse(line2);

    unordered_set<long long> sb;
    sb.reserve(b.size() * 2 + 1);
    for (auto x : b) sb.insert(x);

    vector<long long> res;
    res.reserve(a.size());
    for (auto x : a) {
        if (!sb.count(x)) res.push_back(x);
    }

    sort(res.begin(), res.end(), greater<long long>());

    for (size_t i = 0; i < res.size(); i++) {
        if (i) cout << ' ';
        cout << res[i];
    }
    return 0;
}