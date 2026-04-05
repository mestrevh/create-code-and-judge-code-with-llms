/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string normalize(const string& s) {
    string r;
    r.reserve(s.size());
    for (unsigned char c : s) {
        if (isalnum(c)) r.push_back(tolower(c));
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line, all;
    bool got = false;
    while (getline(cin, line)) {
        if (!got) { all = line; got = true; }
        else all += "\n" + line;
    }
    if (!got) return 0;

    string s = normalize(all);
    int n = (int)s.size();

    bool pal = true;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) { pal = false; break; }
    }

    if (!pal) {
        cout << "NAO";
        return 0;
    }

    int best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int len = 0;
            while (i + len < n && j + len < n && s[i + len] == s[j + len]) len++;
            best = max(best, len);
        }
    }

    cout << "SIM\n" << best;
    return 0;
}