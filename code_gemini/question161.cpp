/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool is_palindrome(const std::string& s) {
    std::string cleaned_str;
    for (char c : s) {
        if (c != ' ') {
            cleaned_str += tolower(c);
        }
    }

    int left = 0;
    int right = cleaned_str.length() - 1;
    while (left < right) {
        if (cleaned_str[left] != cleaned_str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore(); 

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);
        if (is_palindrome(line)) {
            std::cout << "SIM\n";
        } else {
            std::cout << "NAO\n";
        }
    }

    return 0;
}
