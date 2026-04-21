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
    getline(cin, s);

    string out;
    out.reserve(s.size());

    bool inSpace = false;
    for (char c : s) {
        if (c == ' ') {
            if (!inSpace) {
                if (!out.empty()) out.push_back(' ');
                inSpace = true;
            }
        } else {
            out.push_back(c);
            inSpace = false;
        }
    }

    cout << out;
    return 0;
}