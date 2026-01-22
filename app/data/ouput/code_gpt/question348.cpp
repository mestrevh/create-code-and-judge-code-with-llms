/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <string>

int romanToInt(const std::string& s) {
    std::unordered_map<char, int> romanNumerals = {
        {'I', 1}, {'V', 5}, {'X', 10}, 
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int total = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i + 1 < s.size() && romanNumerals[s[i]] < romanNumerals[s[i + 1]]) {
            total -= romanNumerals[s[i]];
        } else {
            total += romanNumerals[s[i]];
        }
    }
    return total;
}

int main() {
    std::string roman;
    std::cin >> roman;
    std::cout << romanToInt(roman) << std::endl;
    return 0;
}
