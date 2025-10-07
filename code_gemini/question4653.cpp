/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::regex virgula("vírgula");
    std::string result = std::regex_replace(line, virgula, ",");
    std::cout << result << std::endl;
    return 0;
}
