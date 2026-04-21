/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline string trim(const string& s) {
    size_t i = 0, j = s.size();
    while (i < j && isspace((unsigned char)s[i])) i++;
    while (j > i && isspace((unsigned char)s[j - 1])) j--;
    return s.substr(i, j - i);
}

static inline string toLowerStr(string s) {
    for (char& c : s) c = (char)tolower((unsigned char)c);
    return s;
}

static inline vector<string> splitByComma(const string& s) {
    vector<string> parts;
    string cur;
    for (char c : s) {
        if (c == ',') {
            parts.push_back(trim(cur));
            cur.clear();
        } else {
            cur.push_back(c);
        }
    }
    parts.push_back(trim(cur));
    return parts;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    string line;
    getline(cin, line);

    for (int i = 0; i < N; i++) {
        getline(cin, line);
        line = trim(line);

        size_t sp = line.find(' ');
        string op = (sp == string::npos) ? line : line.substr(0, sp);
        op = toLowerStr(trim(op));

        string rest = (sp == string::npos) ? "" : trim(line.substr(sp + 1));
        vector<string> args = splitByComma(rest);

        string out;
        if (op == "mov") {
            string a = args.size() > 0 ? args[0] : "";
            string b = args.size() > 1 ? args[1] : "";
            out = a + " = " + b;
        } else if (op == "add") {
            string a = args.size() > 0 ? args[0] : "";
            string b = args.size() > 1 ? args[1] : "";
            out = a + " += " + b;
        } else if (op == "sub") {
            string a = args.size() > 0 ? args[0] : "";
            string b = args.size() > 1 ? args[1] : "";
            out = a + " -= " + b;
        } else if (op == "and") {
            string a = args.size() > 0 ? args[0] : "";
            string b = args.size() > 1 ? args[1] : "";
            out = a + " = " + a + " & " + b;
        }

        cout << out;
        if (i + 1 < N) cout << "\n";
    }

    return 0;
}