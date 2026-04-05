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
            if (!cur.empty()) {
                words.push_back(cur);
                cur.clear();
            }
        } else {
            cur.push_back(c);
        }
    }
    if (!cur.empty()) words.push_back(cur);
    
    for (size_t i = 0; i < words.size(); i++) {
        if (i) cout << ' ';
        cout << words[i];
    }
    return 0;
}