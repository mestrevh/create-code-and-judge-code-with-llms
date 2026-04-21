/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isVowel(char c) {
    c = (char)toupper((unsigned char)c);
    return c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> subs;
    subs.reserve(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = (int)floor(sqrt((double)s.size()));
        int start = -1;
        for (int j = 0; j < (int)s.size(); j++) {
            if (isVowel(s[j])) {
                start = j;
                break;
            }
        }
        if (start == -1) subs.push_back("");
        else {
            int len = min(x, (int)s.size() - start);
            subs.push_back(s.substr(start, len));
        }
    }

    sort(subs.begin(), subs.end());
    string ans;
    for (auto &t : subs) ans += t;
    cout << ans;
    return 0;
}