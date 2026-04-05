/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    if (!cin) return 0;

    int i = 0, n = (int)s.size();
    while (i < n) {
        if (s[i] == '[') {
            int j = i + 1;
            while (j < n && s[j] != ']') j++;
            if (j < n) {
                string inside = s.substr(i + 1, j - i - 1);
                vector<int> codes;
                int cur = 0;
                bool has = false;
                for (int k = 0; k < (int)inside.size(); k++) {
                    char c = inside[k];
                    if (isdigit((unsigned char)c)) {
                        cur = cur * 10 + (c - '0');
                        has = true;
                    } else if (c == '-') {
                        if (has) {
                            codes.push_back(cur);
                            cur = 0;
                            has = false;
                        }
                    }
                }
                if (has) codes.push_back(cur);

                string word;
                word.reserve(codes.size());
                for (int code : codes) word.push_back((char)code);

                int upper = 0, lower = 0;
                for (char ch : word) {
                    if (isupper((unsigned char)ch)) upper++;
                    else if (islower((unsigned char)ch)) lower++;
                }
                if (upper > lower) {
                    for (char &ch : word) ch = (char)toupper((unsigned char)ch);
                } else {
                    for (char &ch : word) ch = (char)tolower((unsigned char)ch);
                }

                s.replace(i, j - i + 1, word);
                n = (int)s.size();
                i += (int)word.size();
                continue;
            }
        }
        i++;
    }

    cout << s;
    return 0;
}