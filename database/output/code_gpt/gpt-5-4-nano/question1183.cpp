/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    if (!getline(cin, a)) return 0;
    if (!getline(cin, b)) return 0;

    auto normalize = [](const string& s) {
        vector<int> cnt(256, 0);
        for (unsigned char ch : s) {
            if (isspace(ch)) continue;
            if (ch == '.' || ch == ',' || ch == '!' || ch == '?') continue;
            ch = (unsigned char)tolower(ch);
            cnt[ch]++;
        }
        return cnt;
    };

    auto ca = normalize(a);
    auto cb = normalize(b);

    cout << (ca == cb ? "True" : "False");
    return 0;
}