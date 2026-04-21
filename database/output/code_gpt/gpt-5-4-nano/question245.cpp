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
    if (!getline(cin, s)) return 0;

    string line;
    getline(cin, line);
    while (line.size() == 0 && cin) {
        if (!getline(cin, line)) break;
    }

    char c = 0;
    for (char ch : line) {
        c = ch;
        break;
    }

    size_t pos = s.find(c);
    if (pos == string::npos) cout << -1 << "\n";
    else cout << pos << "\n";

    return 0;
}