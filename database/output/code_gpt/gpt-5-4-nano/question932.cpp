/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string trimSpaces(const string& s) {
    size_t i = 0, j = s.size();
    while (i < j && isspace((unsigned char)s[i])) i++;
    while (j > i && isspace((unsigned char)s[j - 1])) j--;
    if (i >= j) return "";
    string out;
    bool inSpace = false;
    for (size_t k = i; k < j; k++) {
        char c = s[k];
        if (isspace((unsigned char)c)) {
            if (!out.empty() && !inSpace) {
                out.push_back(' ');
                inSpace = true;
            }
        } else {
            out.push_back(c);
            inSpace = false;
        }
    }
    if (!out.empty() && out.back() == ' ') out.pop_back();
    return out;
}

static string toLowerStr(string t) {
    for (char &c : t) c = (char)tolower((unsigned char)c);
    return t;
}

static string capitalizeWord(const string& w) {
    if (w.empty()) return w;
    string lower = toLowerStr(w);
    string pre;
    string exceptions[] = {"da","de","di","do","du","e"};
    for (auto &ex : exceptions) {
        if (lower == ex) {
            pre = w;
            break;
        }
    }
    bool isException = false;
    for (auto &ex : exceptions) if (lower == ex) isException = true;
    if (isException) {
        string res = lower;
        return res;
    }
    string res = lower;
    res[0] = (char)toupper((unsigned char)res[0]);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    bool firstOutput = true;
    while (true) {
        if (!getline(cin, line)) break;
        if (line == "*") break;

        string cleaned = trimSpaces(line);
        if (cleaned.empty()) continue;

        istringstream iss(cleaned);
        vector<string> words;
        string w;
        while (iss >> w) words.push_back(w);

        for (size_t i = 0; i < words.size(); i++) {
            if (i) cout << ' ';
            cout << capitalizeWord(words[i]);
        }
        cout << "\n";
    }
    return 0;
}