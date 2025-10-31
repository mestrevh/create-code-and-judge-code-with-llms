/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    std::istringstream iss(input);
    std::string word, result;
    
    while (iss >> word) {
        if (!result.empty()) 
            result += ' ';
        result += word;
    }
    
    std::cout << result << std::endl;
    return 0;
}
