/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

void solve() {
    string s1, s2;
    if (!(cin >> s1 >> s2)) return;

    bitset<256> chars;
    for (char c : s1) {
        chars.set((unsigned char)c);
    }

    bool found = false;
    for (char c : s2) {
        if (chars.test((unsigned char)c)) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Compartilham Substring" << "\n";
    } else {
        cout << "Nao Compartilham Substring" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }

    return 0;
}