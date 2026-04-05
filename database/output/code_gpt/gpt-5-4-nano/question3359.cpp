/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> moves;
    string s;
    while (cin >> s) moves.push_back(s);

    auto invertMove = [&](const string& m) -> string {
        if (m.size() >= 2 && m[1] == '2') return m;
        if (!m.empty() && m.back() == '\'') {
            string r = m.substr(0, m.size() - 1);
            return r;
        } else {
            return m + "'";
        }
    };

    for (int i = (int)moves.size() - 1; i >= 0; --i) {
        if (i != (int)moves.size() - 1) cout << ' ';
        cout << invertMove(moves[i]);
    }
    return 0;
}