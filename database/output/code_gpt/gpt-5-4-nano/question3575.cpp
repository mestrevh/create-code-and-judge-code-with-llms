/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string S;
    if (!(cin >> S)) return 0;
    
    string target = "zelda";
    string lower = S;
    for (char &c : lower) c = (char)tolower((unsigned char)c);
    
    if (lower.find(target) != string::npos) {
        cout << "Link Bolado\n";
    } else {
        cout << "Link Tranquilo\n";
    }
    return 0;
}