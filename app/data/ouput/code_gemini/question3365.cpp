/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string digits, chars;
    std::cin >> digits >> chars;

    std::map<char, char> translation_map;
    for (size_t i = 0; i < digits.length(); ++i) {
        translation_map[digits[i]] = chars[i];
    }

    int n;
    std::cin >> n;

    std::string sabotaged_nick;
    for (int i = 0; i < n; ++i) {
        std::cin >> sabotaged_nick;
        for (char &c : sabotaged_nick) {
            if (translation_map.count(c)) {
                c = translation_map[c];
            }
        }
        std::cout << sabotaged_nick << '\n';
    }

    return 0;
}
