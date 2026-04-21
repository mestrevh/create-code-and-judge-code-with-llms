/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string x;
    if (!getline(cin, x)) return 0;
    while (!x.empty() && x.back() == '\r') x.pop_back();

    string line;
    if (!getline(cin, line)) line = "";

    char target = 0;
    for (char c : x) {
        if (!isspace((unsigned char)c)) { target = c; break; }
    }

    long long cnt = 0;
    for (char c : line) if (c == target) cnt++;

    cout << cnt;
    return 0;
}