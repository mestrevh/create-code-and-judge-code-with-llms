/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline string trimCR(string s) {
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) s.pop_back();
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> a, b;
    string line;

    while (getline(cin, line)) {
        line = trimCR(line);
        if (line == "FIM") break;
        a.push_back(line);
    }
    while (getline(cin, line)) {
        line = trimCR(line);
        if (line == "FIM") break;
        b.push_back(line);
    }

    if (!a.empty()) sort(a.begin(), a.end());
    if (!b.empty()) sort(b.begin(), b.end());

    for (auto &s : a) cout << s << "\n";
    for (int i = 0; i < 50; i++) cout << '-';
    cout << "\n";
    for (auto &s : b) cout << s << "\n";
    for (int i = 0; i < 50; i++) cout << '-';
    cout << "\n";

    vector<string> c;
    c.reserve(a.size() + b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));

    for (auto &s : c) cout << s << "\n";
    return 0;
}