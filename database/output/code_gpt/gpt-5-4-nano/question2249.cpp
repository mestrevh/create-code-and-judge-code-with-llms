/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const string symbols = "* ) $ ! + @ - / ( % , . ?";

    string line;
    vector<string> lines;
    while (getline(cin, line)) {
        lines.push_back(line);
    }

    int n = (int)lines.size();
    for (int i = 0; i < n; i++) {
        string s;
        for (char c : lines[n - 1 - i]) {
            if (c == ' ') continue;
            if (isalnum((unsigned char)c)) s.push_back(c);
        }

        string out;
        out.reserve(s.size());

        for (int j = 0; j < (int)s.size(); j++) {
            char c = s[j];
            if (isupper((unsigned char)c)) {
                int val = c - 'A' + 1;
                out.push_back(char('0' + (val % 10)));
                continue;
            }
            if (isdigit((unsigned char)c)) {
                char mapped = 0;
                switch (c) {
                    case '0': mapped = '*'; break;
                    case '1': mapped = ')'; break;
                    case '2': mapped = '$'; break;
                    case '3': mapped = '!'; break;
                    case '4': mapped = '+'; break;
                    case '5': mapped = '@'; break;
                    case '6': mapped = '-'; break;
                    case '7': mapped = '/'; break;
                    case '8': mapped = '('; break;
                    case '9': mapped = '%'; break;
                }
                out.push_back(mapped);
                continue;
            }
            if (islower((unsigned char)c)) {
                int leftCount = 0;
                for (int k = 0; k < j; k++) {
                    char prev = s[k];
                    if (isalnum((unsigned char)prev)) leftCount++;
                }
                if (leftCount % 2 == 0) out.push_back((char)toupper((unsigned char)c));
                else out.push_back(c);
                continue;
            }
        }

        cout << out;
        if (i + 1 < n) cout << "\n";
    }
    return 0;
}