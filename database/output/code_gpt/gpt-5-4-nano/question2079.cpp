/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string normFirstChar(const string& s) {
    if (s.empty()) return "";
    unsigned char c = static_cast<unsigned char>(s[0]);
    if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    return string(1, static_cast<char>(c));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<pair<int, pair<string, string>>> a;
    a.reserve(N);

    for (int i = 0; i < N; i++) {
        string name;
        int h;
        cin >> name >> h;
        string fc = normFirstChar(name);
        a.push_back({h, {name, fc}});
    }

    sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
        if (x.first != y.first) return x.first < y.first;
        return x.second.second < y.second.second;
    });

    for (int i = 0; i < N; i++) {
        if (i) cout << ' ';
        cout << a[i].second.first;
    }
    return 0;
}