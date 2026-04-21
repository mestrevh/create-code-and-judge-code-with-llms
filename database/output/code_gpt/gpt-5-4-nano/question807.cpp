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

    unordered_map<string, string> mp;
    mp.reserve(N * 2);

    for (int i = 0; i < N; i++) {
        string from, arrow, to;
        cin >> from;
        cin >> arrow;
        cin >> to;
        mp[from] = to;
    }

    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        if (line.size() == 1 && line[0] == '*') break;

        stringstream ss(line);
        string word;
        bool first = true;
        while (ss >> word) {
            if (!first) cout << ' ';
            first = false;
            auto it = mp.find(word);
            if (it != mp.end()) cout << it->second;
            else cout << word;
        }
        cout << "\n";
    }

    return 0;
}