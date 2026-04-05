/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> words;
    string line;

    if (!getline(cin, line)) return 0;
    while (line.size() == 0 && !cin.eof()) getline(cin, line);

    {
        istringstream iss(line);
        string w;
        while (iss >> w) words.push_back(w);
    }

    string letterStr;
    if (!(cin >> letterStr)) return 0;
    char target = letterStr.empty() ? '\0' : letterStr[0];

    vector<string> ans;
    for (const auto& w : words) {
        if (!w.empty() && w[0] == target) ans.push_back(w);
    }

    cout << ans.size() << "\n";
    for (const auto& w : ans) cout << w << "\n";
    return 0;
}