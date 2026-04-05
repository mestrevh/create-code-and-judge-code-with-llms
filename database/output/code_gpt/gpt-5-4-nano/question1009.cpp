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
    while (s.size() > 5) s = s.substr(0, 5);
    if (s.size() < 5) {
        while (s.size() < 5) s = "0" + s;
    }
    
    string r = s;
    reverse(r.begin(), r.end());
    cout << (s == r ? 'S' : 'N');
    return 0;
}