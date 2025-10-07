/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <ios>

void solve() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    bool char_set[26] = {false};
    for (char c : s1) {
        if (c >= 'a' && c <= 'z') {
            char_set[c - 'a'] = true;
        }
    }

    bool found = false;
    for (char c : s2) {
        if (c >= 'a' && c <= 'z') {
            if (char_set[c - 'a']) {
                found = true;
                break;
            }
        }
    }

    if (found) {
        std::cout << "Compartilham Substring\n";
    } else {
        std::cout << "Nao Compartilham Substring\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
