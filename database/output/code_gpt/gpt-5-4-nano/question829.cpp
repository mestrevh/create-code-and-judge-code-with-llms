/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<char> s(5);
    for (int i = 0; i < 5; i++) {
        if (!(cin >> s[i])) return 0;
    }
    
    vector<int> p(5);
    for (int i = 0; i < 5; i++) p[i] = s[i] - 'a';
    
    sort(p.begin(), p.end());
    
    bool ok = true;
    for (int i = 1; i < 5; i++) {
        if (p[i] != p[i-1] + 1) {
            ok = false;
            break;
        }
    }
    
    cout << (ok ? "sim" : "nao");
    return 0;
}