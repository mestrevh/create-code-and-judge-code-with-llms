/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    bool first = true;
    while (getline(cin, line)) {
        if (line == "the end!") break;
        for (char &c : line) c = (char)toupper((unsigned char)c);
        if (!first) cout << '\n';
        first = false;
        cout << line;
    }
    return 0;
}