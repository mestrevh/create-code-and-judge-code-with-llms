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
    if (!(cin >> s)) return 0;
    
    string suf = "nte";
    if (s.size() >= 3 && s.substr(s.size() - 3) == suf) s.resize(s.size() - 3);
    
    cout << "Aquilo que " << s << ".\n";
    return 0;
}