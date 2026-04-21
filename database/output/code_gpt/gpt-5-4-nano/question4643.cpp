/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long sum = 0;
    for (int i = 0; i < 5; i++) {
        string s;
        if (!(cin >> s)) return 0;
        char c = s[0];
        sum += (c - 'a' + 1);
    }
    cout << sum << "\n";
    return 0;
}