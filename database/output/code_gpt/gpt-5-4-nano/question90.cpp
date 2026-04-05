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
    bool first = true;
    while (std::getline(cin, line)) {
        if (line == "_") break;
        for (char &c : line) {
            if (c == '+') {
                if (first) {
                    c = '*';
                    first = false;
                } else {
                    c = '#';
                    first = true;
                }
            }
        }
        cout << line;
        if (!cin.eof()) cout << "\n";
    }
    return 0;
}