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
    
    unordered_map<char,int> cnt;
    for (char ch : s) cnt[ch]++;
    
    int odd = 0;
    for (auto &p : cnt) if (p.second % 2 == 1) odd++;
    
    if (odd <= 1) cout << "sim";
    else cout << "nao";
    return 0;
}