/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<char, char> mp = {
        {'0','o'}, {'1','i'}, {'3','e'}, {'4','a'}, {'5','s'}
    };
    
    string s;
    if(!getline(cin, s)) return 0;
    
    for (char &c : s) {
        auto it = mp.find(c);
        if (it != mp.end()) c = it->second;
    }
    
    cout << s;
    return 0;
}