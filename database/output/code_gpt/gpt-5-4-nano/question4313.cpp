/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    string key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<char, char> mp;

    auto add = [&](char a, char b) {
        mp[a] = b;
        mp[b] = a;
    };

    vector<pair<char,char>> pairs = {
        {'A','Z'},{'B','Y'},{'C','X'},{'D','W'},{'E','V'},{'F','U'},{'G','T'},{'H','S'},
        {'I','R'},{'J','Q'},{'K','P'},{'L','O'},{'M','N'},
        {'0','9'},{'1','8'},{'2','7'},{'3','6'},{'4','5'}
    };
    for (auto &pr : pairs) add(pr.first, pr.second);

    vector<string> enc;
    long long totalChars = 0;
    bool ok = true;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.empty()) { ok = false; continue; }
        for (char &c : s) {
            if (mp.find(c) == mp.end()) { ok = false; break; }
        }
        if (!ok) continue;
        string t = s;
        for (char &c : t) c = mp[c];
        totalChars += (long long)s.size();
        enc.push_back(t);
    }

    if (!ok) {
        cout << "Alguma senha eh invalida!";
        return 0;
    }

    for (int i = 0; i < (int)enc.size(); i++) {
        if (i) cout << '-';
        cout << enc[i];
    }
    cout << ' ' << totalChars;
    return 0;
}