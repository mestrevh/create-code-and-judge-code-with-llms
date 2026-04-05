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
    int n = (int)s.size();
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            ans += 1;
            if (i - 1 >= 0 && s[i - 1] == 'i') ans += 1;
            if (i + 1 < n && s[i + 1] == 'i') ans += 1;
        }
    }
    
    cout << ans << "\n";
    return 0;
}