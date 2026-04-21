/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string s;
    while (true) {
        if (!std::getline(cin, s)) break;
        if (!cin && s.size() == 0) {
            if (cin.eof()) break;
        }
        lines.push_back(s);
    }

    if (lines.empty()) return 0;

    size_t maxLen = 0;
    for (auto &x : lines) maxLen = max(maxLen, x.size());

    for (size_t col = 0; col < maxLen; col++) {
        for (int row = (int)lines.size() - 1; row >= 0; row--) {
            if (col < lines[row].size()) cout << lines[row][col];
        }
        if (col + 1 < maxLen) cout << "\n";
    }

    return 0;
}