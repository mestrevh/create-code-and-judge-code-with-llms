/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

void solve() {
    std::string s;
    std::cin >> s;
    if (s.empty()) {
        std::cout << "\n";
        return;
    }
    std::string result = "";
    for (char c : s) {
        if (result.empty() || result.back() != c) {
            result.push_back(c);
        }
    }
    std::cout << result << "\n";
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
