/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    char c;
    std::cin >> s >> c;
    bool found = false;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == c) {
            std::cout << i << "\n";
            found = true;
        }
    }
    std::cout << -1 << "\n";
    return 0;
}
