/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    while (n--) {
        std::string word;
        std::cin >> word;
        std::map<char, char> mapping;
        char next_char = 'a';
        std::string canonical_form = "";
        for (char c : word) {
            if (mapping.find(c) == mapping.end()) {
                mapping[c] = next_char;
                next_char++;
            }
            canonical_form += mapping[c];
        }
        std::cout << canonical_form << '\n';
    }
    return 0;
}
