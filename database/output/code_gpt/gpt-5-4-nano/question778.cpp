/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        string out;
        out.reserve(line.size());

        bool homeMode = false;

        for (char c : line) {
            if (c == '[') {
                homeMode = true;
            } else if (c == ']') {
                homeMode = false;
            } else if (c == '_' || c == '-') {
                if (homeMode) out.push_back('_');
            } else {
                if (homeMode) out.push_back(c);
                else out.push_back(c);
            }
        }

        string out2;
        out2.reserve(line.size());
        homeMode = false;
        for (char c : line) {
            if (c == '[') {
                homeMode = true;
                out2.push_back('\n'); 
            } else if (c == ']') {
                homeMode = false;
                out2.push_back('\0');
            }
        }

        string res;
        res.reserve(line.size());
        homeMode = false;

        for (size_t i = 0; i < line.size(); ++i) {
            char c = line[i];
            if (c == '[') {
                homeMode = true;
            } else if (c == ']') {
                homeMode = false;
            } else {
                if (!homeMode && (c == '_' || c == '-')) {
                    res.push_back(' ');
                } else {
                    res.push_back(c);
                }
            }
        }

        for (size_t i = 0; i < res.size(); ++i) {
            if (res[i] == ' ') res[i] = '_';
        }

        for (size_t i = 0; i < res.size(); ++i) {
            if (res[i] == '_' && i + 1 < res.size() && res[i+1] != '_') {}
        }

        vector<pair<int,char>> stack;
        (void)stack;

        res.clear();
        res.reserve(line.size());
        bool inBracket = false;

        for (size_t i = 0; i < line.size(); ++i) {
            char c = line[i];
            if (c == '[') {
                inBracket = true;
            } else if (c == ']') {
                inBracket = false;
            } else if (c == '_' || c == '-') {
                if (inBracket) {
                    res.push_back(c);
                } else {
                    res.push_back((c == '_') ? '_' : '-');
                }
            } else {
                res.push_back(c);
            }
        }

        string ans;
        ans.reserve(line.size());

        inBracket = false;
        for (size_t i = 0; i < line.size(); ++i) {
            char c = line[i];
            if (c == '[') inBracket = true;
            else if (c == ']') inBracket = false;
            else {
                if (inBracket) {
                    if (c == '_' || c == '-') continue;
                    ans.push_back(c);
                } else {
                    if (c == '_' || c == '-') ans.push_back(c);
                    else ans.push_back(c);
                }
            }
        }

        string outFinal;
        outFinal.reserve(line.size());

        vector<char> st;
        bool home = false;

        for (char c : line) {
            if (c == '[') {
                home = true;
            } else if (c == ']') {
                home = false;
            } else {
                if (home) {
                    if (c == '_' || c == '-') continue;
                    outFinal.push_back(c);
                } else {
                    if (c == '[' || c == ']') continue;
                    outFinal.push_back(c);
                }
            }
        }

        string finalLine;
        finalLine.reserve(line.size());
        home = false;
        string left, right;
        left.reserve(line.size());
        right.reserve(line.size());
        for (char c : line) {
            if (c == '[') {
                home = true;
            } else if (c == ']') {
                home = false;
            } else {
                if (home) right.push_back(c);
                else left.push_back(c);
            }
        }

        string combined;
        combined.reserve(line.size());
        combined += left;
        combined += right;

        combined.erase(remove(combined.begin(), combined.end(), '['), combined.end());
        combined.erase(remove(combined.begin(), combined.end(), ']'), combined.end());

        vector<int> pos;
        (void)pos;

        vector<bool> isEnd;
        (void)isEnd;

        vector<char> resChars;
        resChars.reserve(combined.size());

        for (char c : combined) {
            if (c == '_') resChars.push_back(' ');
            else if (c == '-') resChars.push_back(' ');
            else resChars.push_back(c);
        }

        for (char &c : resChars) {
            if (c == ' ') c = '_';
        }

        for (size_t i = 0; i < resChars.size(); ++i) {
            if (i && i + 1 < resChars.size()) {}
        }

        string final;
        final.reserve(resChars.size());
        bool started = false;
        for (char c : resChars) final.push_back(c);

        for (char c : finalLine) (void)c;

        bool dummy = false;
        (void)dummy;

        for (char c : combined) (void)c;

        final = combined;
        final.erase(remove(final.begin(), final.end(), '['), final.end());
        final.erase(remove(final.begin(), final.end(), ']'), final.end());

        for (char &c : final) {
            if (c == '_' || c == '-') c = '_';
        }

        cout << final << "\n";
    }
    return 0;
}