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
    
    vector<char> leftPart, rightPart;
    leftPart.reserve(s.size());
    rightPart.reserve(s.size());
    
    bool atStart = true;
    for (char c : s) {
        if (c == '[') {
            atStart = false;
        } else if (c == ']') {
            rightPart.clear();
            atStart = false;
        } else {
            if (atStart) rightPart.push_back(c);
            else rightPart.push_back(c);
        }
    }
    
    deque<char> dq;
    bool home = true;
    for (char c : s) {
        if (c == '[') {
            home = false;
            continue;
        }
        if (c == ']') {
            home = true;
            continue;
        }
        if (home) {
            dq.push_back(c);
        } else {
            dq.push_front(c);
        }
    }
    
    for (char c : dq) cout << c;
    cout << "\n";
    return 0;
}