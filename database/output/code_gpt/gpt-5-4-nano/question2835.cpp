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

    map<char, long long> freq;
    for (unsigned char c : s) freq[(char)c]++;

    for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
        char ch = it->first;
        long long cnt = it->second;

        if (ch == ' ') cout << ' ' << ' ' << cnt << "\n";
        else cout << ch << ' ' << cnt << "\n";
    }
    return 0;
}