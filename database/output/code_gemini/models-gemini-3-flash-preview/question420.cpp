/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string target = "the quick brown fox jumps over the lazy dog";

void solve() {
    string s;
    vector<string> inputs;
    while (getline(cin, s)) {
        if (!s.empty() && s.back() == '\r') s.pop_back();
        if (s.empty()) {
            if (inputs.empty()) continue;
            else break;
        }
        inputs.push_back(s);
    }

    if (inputs.empty()) return;

    char mapping[256];
    bool found = false;

    for (const string& cand : inputs) {
        if (cand.length() != target.length()) continue;

        char s_to_t[256] = {0};
        char t_to_s[256] = {0};
        bool possible = true;

        for (int i = 0; i < (int)target.length(); ++i) {
            if (cand[i] == ' ') {
                if (target[i] != ' ') { 
                    possible = false; 
                    break; 
                }
            } else {
                if (target[i] == ' ') { 
                    possible = false; 
                    break; 
                }
                unsigned char sc = (unsigned char)cand[i];
                unsigned char tc = (unsigned char)target[i];
                if (s_to_t[sc] == 0 && t_to_s[tc] == 0) {
                    s_to_t[sc] = tc;
                    t_to_s[tc] = sc;
                } else if (s_to_t[sc] != tc || t_to_s[tc] != sc) {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            for (int i = 0; i < 256; ++i) mapping[i] = s_to_t[i];
            found = true;
            break;
        }
    }

    if (found) {
        for (const string& cand : inputs) {
            for (char c : cand) {
                if (c == ' ') cout << ' ';
                else cout << mapping[(unsigned char)c];
            }
            cout << "\n";
        }
    } else {
        cout << "No solution.\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line) || line.empty()) return 0;
    
    int t;
    try {
        t = stoi(line);
    } catch (...) {
        return 0;
    }

    for (int i = 0; i < t; ++i) {
        if (i > 0) cout << "\n";
        solve();
    }

    return 0;
}