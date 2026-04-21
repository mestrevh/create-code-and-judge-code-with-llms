/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    char C;

    if (!getline(cin, S)) return 0;
    string line;
    if (!getline(cin, line)) return 0;

    if (line.empty()) return 0;
    C = line[0];

    size_t pos = S.find(C);
    if (pos == string::npos) cout << -1;
    else cout << pos;

    return 0;
}