/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string line;
    while (true) {
        if (!getline(cin, line)) break;
        for (char &c : line) {
            if (c >= 'A' && c <= 'Z') {
                c = char('A' + (c - 'A' + 6) % 26);
            } else if (c >= 'a' && c <= 'z') {
                c = char('a' + (c - 'a' + 6) % 26);
            }
        }
        cout << line;
        if (!cin.eof()) cout << "\n";
    }
    return 0;
}