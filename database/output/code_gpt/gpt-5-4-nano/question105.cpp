/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static const int ALPHA = 26;
static const char AST = '*';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> dict(n);
    for (int i = 0; i < n; i++) cin >> dict[i];

    unordered_set<string> dictSet;
    dictSet.reserve(n * 2);
    for (auto &w : dict) dictSet.insert(w);

    string line;
    string dummy;
    getline(cin, dummy); // consume endline after last dictionary word

    auto allStar = [](const string& s) {
        string t = s;
        for (char &c : t) if (c >= 'a' && c <= 'z') c = AST;
        return t;
    };

    vector<pair<string, int>> words; // word and length
    // Process each input line until EOF
    while (true) {
        if (!std::getline(cin, line)) break;
        if (line.size() == 0) {
            cout << "\n";
            continue;
        }

        vector<string> tokens;
        {
            string cur;
            for (char c : line) {
                if (c == ' ') {
                    if (!cur.empty()) {
                        tokens.push_back(cur);
                        cur.clear();
                    } else {
                        tokens.push_back("");
                    }
                } else {
                    cur.push_back(c);
                }
            }
            if (!cur.empty()) tokens.push_back(cur);
            // input uses single spaces likely; but we handle exactly one or multiple spaces by reconstructing later
        }

        // Better: parse keeping spaces
        vector<string> tok; // words and separators
        tok.reserve(200);
        {
            string w;
            for (size_t i = 0; i < line.size(); i++) {
                char c = line[i];
                if (c == ' ') {
                    if (!w.empty()) {
                        tok.push_back(w);
                        w.clear();
                    }
                    tok.push_back(string(1, ' '));
                } else {
                    w.push_back(c);
                }
            }
            if (!w.empty()) tok.push_back(w);
        }

        vector<string> encWords;
        for (auto &t : tok) {
            if (!t.empty() && t[0] != ' ') encWords.push_back(t);
        }

        bool hasOnlyLower = true;
        for (char c : line) {
            if (!(c == ' ' || (c >= 'a' && c <= 'z'))) { hasOnlyLower = false; break; }
        }

        // Build candidates grouped by length and exact cipher length
        unordered_map<int, vector<string>> byLen;
        byLen.reserve(64);
        for (auto &w : dict) byLen[w.size()].push_back(w);

        vector<vector<string>> candidates(encWords.size());
        for (size_t i = 0; i < encWords.size(); i++) {
            auto it = byLen.find((int)encWords[i].size());
            if (it != byLen.end()) candidates[i] = it->second;
        }

        // Precompute letter pattern signature to prune: map each char pattern in word.
        auto signature = [&](const string& s) {
            array<int, 26> id;
            id.fill(-1);
            int cnt = 0;
            vector<int> sig;
            sig.reserve(s.size());
            for (char c : s) {
                int idx = c - 'a';
                if (id[idx] == -1) id[idx] = cnt++;
                sig.push_back(id[idx]);
            }
            return sig;
        };

        unordered_map<int, vector<pair<string, vector<int>>>> sigMap; // not used directly
        // We'll compute signatures on candidates per position and filter quickly using mapping constraints during backtracking.

        // Backtracking with global bijection constraints cipher->plain and plain->cipher
        array<int, ALPHA> c2p, p2c;
        array<int, ALPHA> need; need.fill(-1);
        c2p.fill(-1);
        p2c.fill(-1);

        vector<int> assignCipherToPlain(ALPHA, -1); // c2p
        vector<int> assignPlainToCipher(ALPHA, -1); // p2c

        // Order words by fewest candidates
        vector<int> order(encWords.size());
        iota(order.begin(), order.end(), 0);

        auto consistentWord = [&](int pos, const string& plain) -> bool {
            const string& cipher = encWords[pos];
            int m = cipher.size();
            for (int i = 0; i < m; i++) {
                int cc = cipher[i] - 'a';
                int pc = plain[i] - 'a';
                int mapped = c2p[cc];
                if (mapped != -1 && mapped != pc) return false;
                int mappedBack = p2c[pc];
                if (mappedBack != -1 && mappedBack != cc) return false;
            }
            return true;
        };

        auto applyWord = [&](int pos, const string& plain, vector<pair<int,int>>& changes) {
            const string& cipher = encWords[pos];
            int m = cipher.size();
            for (int i = 0; i < m; i++) {
                int cc = cipher[i] - 'a';
                int pc = plain[i] - 'a';
                if (c2p[cc] == -1) {
                    changes.push_back({cc, c2p[cc]});
                    c2p[cc] = pc;
                }
                if (p2c[pc] == -1) {
                    changes.push_back({26 + pc, p2c[pc]});
                    p2c[pc] = cc;
                }
            }
        };

        auto rollback = [&](vector<pair<int,int>>& changes) {
            for (int i = (int)changes.size()-1; i >= 0; i--) {
                int idx = changes[i].first;
                int oldv = changes[i].second;
                if (idx < 26) c2p[idx] = oldv;
                else p2c[idx-26] = oldv;
            }
            changes.clear();
        };

        // refine candidate list by pattern equality constraints (internal structure)
        // Two words can only match under bijection if their repeated-letter pattern is identical.
        unordered_map<int, vector<string>> dictBySigLen;
        dictBySigLen.reserve(n * 2);

        // Build signature->words for each length
        unordered_map<long long, vector<string>> sigKeyToWords;
        sigKeyToWords.reserve(n * 2);
        auto makeSigKey = [&](const string& s) {
            // compute normalized ids; pack into 64-bit with separators might overflow; instead hash string
            auto sig = signature(s);
            size_t h = 1469598103934665603ull;
            for (int x: sig) {
                h ^= (size_t)x + 0x9e3779b97f4a7c15ull;
                h *= 1099511628211ull;
            }
            h ^= (size_t)s.size() + 0x9e3779b97f4a7c15ull;
            return (long long)h;
        };

        for (auto &w : dict) {
            long long key = makeSigKey(w);
            sigKeyToWords[key].push_back(w);
        }

        for (size_t i = 0; i < encWords.size(); i++) {
            long long key = makeSigKey(encWords[i]);
            auto it = sigKeyToWords.find(key);
            if (it != sigKeyToWords.end()) candidates[i] = it->second;
            else candidates[i].clear();
        }

        // reorder by candidate size
        sort(order.begin(), order.end(), [&](int a, int b){
            if (candidates[a].size() != candidates[b].size()) return candidates[a].size() < candidates[b].size();
            return a < b;
        });

        vector<string> chosen(encWords.size());
        bool found = false;

        function<void(int)> dfs = [&](int idxOrder) {
            if (found) return;
            if (idxOrder == (int)order.size()) {
                found = true;
                return;
            }
            int pos = order[idxOrder];
            if (candidates[pos].empty()) return;

            // Sort candidates optionally to help: could try those that fit with current partial mapping
            for (const string& plain : candidates[pos]) {
                if (!consistentWord(pos, plain)) continue;
                vector<pair<int,int>> changes;
                changes.reserve(60);
                applyWord(pos, plain, changes);
                chosen[pos] = plain;
                dfs(idxOrder + 1);
                if (found) return;
                chosen[pos].clear();
                rollback(changes);
            }
        };

        dfs(0);

        if (!found) {
            cout << allStar(line) << "\n";
        } else {
            // Reconstruct output preserving spaces and original token positions
            size_t wordIdx = 0;
            string out;
            out.reserve(line.size());
            for (auto &t : tok) {
                if (!t.empty() && t[0] != ' ') {
                    out += chosen[wordIdx++];
                } else {
                    out += t;
                }
            }
            cout << out << "\n";
        }
    }

    return 0;
}