/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

vector<string> dict[17];
char res_map[26];

bool backtrack(int idx, const vector<string>& words, char m[26], char rm[26]) {
    if (idx == (int)words.size()) {
        memcpy(res_map, m, 26);
        return true;
    }

    const string& e = words[idx];
    int len = e.length();

    if (dict[len].empty()) return false;

    for (const string& d : dict[len]) {
        char nm[26], nrm[26];
        memcpy(nm, m, 26);
        memcpy(nrm, rm, 26);
        bool ok = true;
        for (int i = 0; i < len; ++i) {
            int u = e[i] - 'a';
            int v = d[i] - 'a';
            if ((nm[u] != 0 && nm[u] != d[i]) || (nrm[v] != 0 && nrm[v] != e[i])) {
                ok = false;
                break;
            }
            nm[u] = d[i];
            nrm[v] = e[i];
        }
        if (ok && backtrack(idx + 1, words, nm, nrm)) return true;
    }
    return false;
}

bool compareLength(const string& a, const string& b) {
    return a.length() > b.length();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s.length() < 17) {
            dict[s.length()].push_back(s);
        }
    }

    string line;
    getline(cin, line); 

    while (getline(cin, line)) {
        if (line.empty()) {
            cout << "\n";
            continue;
        }

        stringstream ss(line);
        string w;
        vector<string> words_in_line;
        set<string> unique_words;
        while (ss >> w) {
            if (unique_words.find(w) == unique_words.end()) {
                unique_words.insert(w);
                words_in_line.push_back(w);
            }
        }

        sort(words_in_line.begin(), words_in_line.end(), compareLength);

        char m[26], rm[26];
        memset(m, 0, 26);
        memset(rm, 0, 26);
        memset(res_map, 0, 26);

        if (backtrack(0, words_in_line, m, rm)) {
            for (int i = 0; i < (int)line.length(); ++i) {
                if (line[i] == ' ') cout << ' ';
                else cout << res_map[line[i] - 'a'];
            }
        } else {
            for (int i = 0; i < (int)line.length(); ++i) {
                if (line[i] == ' ') cout << ' ';
                else cout << '*';
            }
        }
        cout << "\n";
    }

    return 0;
}