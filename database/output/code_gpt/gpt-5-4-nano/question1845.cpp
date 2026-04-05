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

    while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) s.pop_back();

    if (s.empty()) {
        cout << "";
        return 0;
    }

    for (char &c : s) c = (char)tolower((unsigned char)c);
    reverse(s.begin(), s.end());

    s[0] = (char)toupper((unsigned char)s[0]);
    s[s.size() - 1] = (char)toupper((unsigned char)s[s.size() - 1]);

    cout << s;
    return 0;
}