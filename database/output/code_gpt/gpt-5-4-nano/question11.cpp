/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool startsWithAt(const string& s, size_t pos, const string& pat) {
    if (pos + pat.size() > s.size()) return false;
    for (size_t i = 0; i < pat.size(); ++i)
        if (s[pos + i] != pat[i]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        string dummy;
        getline(cin, dummy);

        vector<pair<string,string>> rules;
        rules.reserve(n);

        for (int i = 0; i < n; ++i) {
            string line;
            getline(cin, line);

            size_t arrow = line.find(" -> ");
            string a = (arrow == string::npos) ? line : line.substr(0, arrow);
            string b = (arrow == string::npos) ? "" : line.substr(arrow + 4);
            rules.push_back({a, b});
        }

        vector<string> text(m);
        for (int i = 0; i < m; ++i) getline(cin, text[i]);

        for (int i = 0; i < m; ++i) {
            string s = text[i];
            bool changed = true;

            while (changed) {
                changed = false;
                string out;
                out.reserve(s.size());

                for (size_t pos = 0; pos < s.size(); ) {
                    bool replaced = false;

                    for (const auto& [from, to] : rules) {
                        if (!from.empty() && startsWithAt(s, pos, from)) {
                            out += to;
                            pos += from.size();
                            replaced = true;
                            changed = true;
                            break;
                        }
                    }

                    if (!replaced) {
                        out.push_back(s[pos]);
                        ++pos;
                    }
                }

                s.swap(out);
            }

            cout << s << "\n";
        }
    }

    return 0;
}