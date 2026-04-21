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
    
    vector<string> parts;
    string cur;
    for (char c : s) {
        if (isdigit(static_cast<unsigned char>(c))) cur.push_back(c);
        else {
            if (!cur.empty()) {
                parts.push_back(cur);
                cur.clear();
            }
        }
    }
    if (!cur.empty()) parts.push_back(cur);
    
    for (int i = 0; i < 4 && i < (int)parts.size(); i++) {
        cout << parts[i] << "\n";
    }
    return 0;
}