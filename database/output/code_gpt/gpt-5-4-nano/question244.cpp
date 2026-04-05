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
    if (!getline(cin, line)) return 0;

    char c = 0;
    for (char ch : line) {
        if (!isspace(static_cast<unsigned char>(ch))) {
            c = ch;
            break;
        }
    }

    int cnt = 0;
    for (char ch : s) {
        if (ch == c) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}