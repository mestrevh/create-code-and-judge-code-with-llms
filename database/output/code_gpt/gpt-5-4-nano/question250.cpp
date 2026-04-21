/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    char c;

    if (!getline(cin, s)) return 0;
    string line;
    if (!getline(cin, line)) return 0;
    while (line.size() == 0 && cin) getline(cin, line);
    c = line.empty() ? '\0' : line[0];

    size_t pos = 0;
    bool found = false;
    while (true) {
        pos = s.find(c, pos);
        if (pos == string::npos) break;
        cout << pos << "\n";
        pos++;
        found = true;
    }
    if (!found) cout << -1 << "\n";
    else cout << -1 << "\n";

    return 0;
}