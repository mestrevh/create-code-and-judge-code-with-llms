/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>
#include <regex>

bool isValidName(const std::string& name) {
    if (name.length() < 3 || name.length() > 30) return false;
    if (!std::isalpha(name.front()) || !std::isalpha(name.back())) return false;

    std::regex regex("^[A-Z][a-z]*( [A-Z][a-z]*|(-[A-Z][a-z]*))*$");
    if (!std::regex_match(name, regex)) return false;

    for (size_t i = 1; i < name.length(); i++) {
        if ((name[i] == ' ' || name[i] == '-') && (name[i-1] == ' ' || name[i-1] == '-'))
            return false;
    }

    return true;
}

int main() {
    std::string name;
    std::getline(std::cin, name);

    if (isValidName(name)) 
        std::cout << name << ": 1" << std::endl;
    else 
        std::cout << name << ": 0" << std::endl;

    return 0;
}
