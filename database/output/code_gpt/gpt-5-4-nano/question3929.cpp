/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    string s;
    cin >> s;
    long long X;
    cin >> X;

    int shift = (int)(X % 26);
    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            int v = c - 'a';
            v = (v + shift) % 26;
            s[i] = char('a' + v);
        }
    }

    cout << s;
    return 0;
}