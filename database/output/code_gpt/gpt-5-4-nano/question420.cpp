/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct CaseData {
    vector<string> enc;
    string plain;
};

static const string KNOWN_PLAIN = "the quick brown fox jumps over the lazy dog";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    string line;
    getline(cin, line);

    for (int tc = 0; tc < T; tc++) {
        if (tc) cout << "\n";

        vector<string> enc;
        while (true) {
            if (!std::getline(cin, line)) break;
            if (!line.empty() && line.back()=='\r') line.pop_back();

            bool isBlank = true;
            for (char c : line) if (c != ' ' && c != '\t' && c != '\r') { isBlank = false; break; }

            if (isBlank) {
                if (!enc.empty()) break;
                else continue;
            } else {
                if ((int)enc.size() > 1000000) break;
                enc.push_back(line);
            }
        }

        if (enc.empty()) {
            cout << "No solution.\n";
            continue;
        }

        vector<int> candIdx;
        for (int i = 0; i < (int)enc.size(); i++) {
            if (enc[i].size() == KNOWN_PLAIN.size()) candIdx.push_back(i);
        }

        auto try_decode_with_mapping = [&](const string& cipherLine) -> optional<string> {
            vector<int> mp(26, -1), inv(26, -1);
            for (int k = 0; k < (int)cipherLine.size(); k++) {
                char c = cipherLine[k];
                char p = KNOWN_PLAIN[k];
                if (c == ' ' || p == ' ') {
                    if (c != p) return nullopt;
                    continue;
                }
                if (c < 'a' || c > 'z' || p < 'a' || p > 'z') return nullopt;
                int x = c - 'a';
                int y = p - 'a';
                if (mp[x] == -1 && inv[y] == -1) {
                    mp[x] = y;
                    inv[y] = x;
                } else {
                    if (mp[x] != y) return nullopt;
                    if (inv[y] != x) return nullopt;
                }
            }

            for (int i = 0; i < (int)enc.size(); i++) {
                const string& s = enc[i];
                if (s.size() == KNOWN_PLAIN.size()) {
                    bool ok = true;
                    for (int k = 0; k < (int)s.size(); k++) {
                        char c = s[k];
                        char p = KNOWN_PLAIN[k];
                        if (c == ' ' || p == ' ') {
                            if (c != p) { ok = false; break; }
                            continue;
                        }
                        int x = c - 'a';
                        if (mp[x] == -1) { ok = false; break; }
                        if (mp[x] != (p - 'a')) { ok = false; break; }
                    }
                    if (!ok) return nullopt;
                }
            }

            for (int i = 0; i < (int)enc.size(); i++) {
                for (char c : enc[i]) {
                    if (c == ' ') continue;
                    int x = c - 'a';
                    if (mp[x] == -1) return nullopt;
                }
            }

            stringstream out;
            for (int i = 0; i < (int)enc.size(); i++) {
                string dec;
                dec.reserve(enc[i].size());
                for (char c : enc[i]) {
                    if (c == ' ') dec.push_back(' ');
                    else dec.push_back(char('a' + mp[c - 'a']));
                }
                if (i) out << "\n";
                out << dec;
            }
            return out.str();
        };

        optional<string> best;
        for (int idx : candIdx) {
            auto res = try_decode_with_mapping(enc[idx]);
            if (res.has_value()) {
                best = res;
                break;
            }
        }

        if (!best.has_value()) cout << "No solution.\n";
        else {
            cout << *best << "\n";
        }
    }

    return 0;
}