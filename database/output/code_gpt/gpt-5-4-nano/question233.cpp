/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    unordered_map<string, long long> dict;
    dict.reserve(m * 2);

    for (int i = 0; i < m; i++) {
        string w;
        long long val;
        cin >> w >> val;
        dict[w] = val;
    }

    string line;
    getline(cin, line);

    for (int i = 0; i < n; i++) {
        long long sum = 0;
        while (true) {
            if (!getline(cin, line)) break;
            if (line.find('.') != string::npos) break;

            string cur;
            for (char c : line) {
                if (c == ' ' || c == '\r' || c == '\t') {
                    if (!cur.empty()) {
                        auto it = dict.find(cur);
                        if (it != dict.end()) sum += it->second;
                        cur.clear();
                    }
                } else {
                    cur.push_back(c);
                }
            }
            if (!cur.empty()) {
                auto it = dict.find(cur);
                if (it != dict.end()) sum += it->second;
            }
        }
        cout << sum;
        if (i + 1 < n) cout << "\n";
    }
    return 0;
}