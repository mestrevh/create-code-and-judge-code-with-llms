/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

std::string createPalindrome(const std::string &s) {
    std::string reversed = s;
    std::reverse(reversed.begin(), reversed.end());
    return s + s + s + reversed + reversed + reversed;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    std::cout << createPalindrome(input) << std::endl;
    return 0;
}
