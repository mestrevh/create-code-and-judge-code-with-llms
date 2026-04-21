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
    if (s.size() != 3) {
        while (s.size() < 3) s = "0" + s;
        if (s.size() > 3) s = s.substr(s.size() - 3);
    }
    reverse(s.begin(), s.end());
    cout << s;
    return 0;
}