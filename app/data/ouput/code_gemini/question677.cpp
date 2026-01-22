/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void solve() {
    std::string s;
    std::cin >> s;
    int n;
    std::cin >> n;
    std::unordered_map<char, std::string> shortcuts;
    for (int i = 0; i < n; ++i) {
        char c;
        std::string a;
        std::cin >> c >> a;
        shortcuts[c] = a;
    }

    std::string result = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '*' && i + 1 < s.length()) {
            char next_char = s[i + 1];
            if (shortcuts.count(next_char)) {
                result += shortcuts.at(next_char);
                i++;
            } else {
                result += s[i];
            }
        } else {
            result += s[i];
        }
    }
    std::cout << result << '\n';
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
