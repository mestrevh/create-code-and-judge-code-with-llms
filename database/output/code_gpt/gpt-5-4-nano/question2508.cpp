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
    string line;
    getline(cin, line);

    for (int tc = 0; tc < N; tc++) {
        getline(cin, line);
        istringstream iss(line);
        set<string> items;
        string w;
        while (iss >> w) items.insert(w);
        bool first = true;
        for (const auto& s : items) {
            if (!first) cout << ' ';
            first = false;
            cout << s;
        }
        if (tc + 1 < N) cout << "\n";
    }
    return 0;
}