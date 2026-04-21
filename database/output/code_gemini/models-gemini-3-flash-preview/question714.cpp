/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    if (!std::getline(std::cin, s)) return 0;
    
    // Remove potential carriage return from Windows-style line endings
    if (!s.empty() && s.back() == '\r') {
        s.pop_back();
    }

    char c;
    if (!(std::cin >> c)) {
        std::cout << -1 << std::endl;
        return 0;
    }

    int found_index = -1;
    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] == c) {
            found_index = i;
            break;
        }
    }

    std::cout << found_index << std::endl;

    return 0;
}