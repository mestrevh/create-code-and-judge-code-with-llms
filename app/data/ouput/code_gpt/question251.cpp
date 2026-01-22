/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);

    std::unordered_set<char> chars_to_remove(s2.begin(), s2.end());
    std::string result;

    for (char c : s1) {
        if (chars_to_remove.find(c) == chars_to_remove.end()) {
            result += c;
        }
    }

    std::cout << result << std::endl;
    return 0;
}
