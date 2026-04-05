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
    getline(cin, s);
    int count = 0;
    for (char c : s) {
        if (c >= '0' && c <= '9') count++;
    }
    cout << count << "\n";
    return 0;
}