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
    bool first = true;
    while (cin >> n) {
        if (n == 0) break;
        string line;
        getline(cin, line);

        vector<string> names;
        names.reserve(n);
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            names.push_back(line);
        }

        sort(names.begin(), names.end());

        if (!first) {}
        first = false;

        for (int i = 0; i < n; i++) {
            cout << names[i] << "\n";
        }
    }
    return 0;
}