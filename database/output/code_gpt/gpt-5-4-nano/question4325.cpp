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
    if (!getline(cin, s)) return 0;

    vector<char> st;
    for (size_t i = 0; i < s.size(); ) {
        char c = s[i];
        if (c == '<') {
            if (i + 2 < s.size() && (s[i+1] == 'B' || s[i+1] == 'b')) {
                if (s.find("/>", i) != string::npos || s.find('>', i) != string::npos) {
                    if (!st.empty()) st.pop_back();
                    size_t j = s.find('>', i);
                    if (j == string::npos) break;
                    i = j + 1;
                    continue;
                }
            }
            if (i + 2 < s.size() && (s[i+1] == 'Z' || s[i+1] == 'z')) {
                if (!st.empty()) st.pop_back();
                size_t j = s.find('>', i);
                if (j == string::npos) break;
                i = j + 1;
                continue;
            }
            size_t j = s.find('>');
            if (j == string::npos) break;
            i = j + 1;
            continue;
        }

        if (c == '<') {
            i++;
            continue;
        }

        st.push_back(c);
        i++;
    }

    for (char c : st) cout << c;
    cout << "\n";
    return 0;
}