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

    unordered_set<string> s;
    s.reserve((size_t)n * 2);

    string line;
    getline(cin, line);

    for (int i = 0; i < n; i++) {
        if (!getline(cin, line)) line.clear();
        s.insert(line);
    }

    string query;
    if (!getline(cin, query)) query.clear();

    cout << (s.find(query) != s.end() ? "Sim" : "Não");
    return 0;
}