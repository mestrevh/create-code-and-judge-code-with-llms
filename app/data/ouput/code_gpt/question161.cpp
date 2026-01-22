/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool isPalindrome(const std::string& str) {
    std::string cleaned;
    for (char ch : str) {
        if (!isspace(ch)) {
            cleaned += tolower(ch);
        }
    }
    std::string reversed = cleaned;
    std::reverse(reversed.begin(), reversed.end());
    return cleaned == reversed;
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); 
    for (int i = 0; i < n; ++i) {
        std::string input;
        std::getline(std::cin, input);
        if (isPalindrome(input)) {
            std::cout << "SIM" << std::endl;
        } else {
            std::cout << "NAO" << std::endl;
        }
    }
    return 0;
}
