/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>

std::string preprocess(const std::string &s) {
    std::string result;
    for (char c : s) {
        if (std::isalpha(c)) {
            result += std::tolower(c);
        }
    }
    return result;
}

bool areAnagrams(const std::string &str1, const std::string &str2) {
    std::string processed1 = preprocess(str1);
    std::string processed2 = preprocess(str2);
    
    std::map<char, int> count;
    
    for (char c : processed1) count[c]++;
    for (char c : processed2) count[c]--;
    
    for (const auto &pair : count) {
        if (pair.second != 0) return false;
    }
    
    return true;
}

int main() {
    std::string line1, line2;
    std::getline(std::cin, line1);
    std::getline(std::cin, line2);
    
    std::cout << (areAnagrams(line1, line2) ? "True" : "False") << std::endl;
    
    return 0;
}
