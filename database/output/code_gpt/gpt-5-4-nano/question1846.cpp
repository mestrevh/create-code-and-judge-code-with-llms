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
    if (!s.empty() && s.back() == '\r') s.pop_back();

    string up;
    up.reserve(s.size());
    for (unsigned char c : s) up.push_back(toupper(c));

    for (size_t i = 0; i < up.size(); i++) {
        cout << up.substr(0, i + 1);
        if (i + 1 < up.size()) cout << "\n";
    }
    return 0;
}