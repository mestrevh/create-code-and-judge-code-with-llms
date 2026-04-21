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

    vector<string> words;
    string cur;
    for (char c : s) {
        if (c == ' ') {
            words.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(c);
        }
    }
    words.push_back(cur);

    stack<char> st;
    string out;
    for (size_t i = 0; i < words.size(); i++) {
        for (char c : words[i]) st.push(c);
        string rev;
        while (!st.empty()) {
            rev.push_back(st.top());
            st.pop();
        }
        out += rev;
        if (i + 1 < words.size()) out += ' ';
    }

    cout << out;
    return 0;
}