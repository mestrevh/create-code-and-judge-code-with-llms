/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int count_chars(std::string s) {
    if (s.empty()) {
        return 0;
    }
    return 1 + count_chars(s.substr(1));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string input_line;
    std::getline(std::cin, input_line);
    std::cout << count_chars(input_line) << std::endl;
    return 0;
}
