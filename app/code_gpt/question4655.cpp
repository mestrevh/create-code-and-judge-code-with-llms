/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>

std::string transform(const std::string& input) {
    std::unordered_map<char, std::string> replacements = {
        {'a', "4"}, {'e', "3"}, {'i', "1"}, {'o', "0"}, {'s', "5"}, {'t', "7"}
    };
    std::string output;

    for (char c : input) {
        if (replacements.find(c) != replacements.end()) {
            output += replacements[c];
        } else {
            output += c;
        }
    }
    return output;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    std::string result = transform(input);
    std::cout << result << std::endl;

    return 0;
}
