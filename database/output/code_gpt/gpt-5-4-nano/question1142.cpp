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

    string v;
    for (char c : s) {
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') v.push_back(c);
    }

    string vr = v;
    reverse(vr.begin(), vr.end());

    cout << (v == vr ? "S" : "N") << "\n";
    return 0;
}