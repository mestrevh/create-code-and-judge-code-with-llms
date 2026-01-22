/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cctype>
#include <string>

bool isValidPassword(const std::string &password) {
    if (password.length() < 10) return false;

    bool hasUpper = false, hasLower = false, hasDigit = false;
    for (char ch : password) {
        if (std::isupper(ch)) hasUpper = true;
        else if (std::islower(ch)) hasLower = true;
        else if (std::isdigit(ch)) hasDigit = true;
        else if (!std::isspace(ch)) return false;
    }

    if (!hasUpper || !hasLower || !hasDigit) return false;

    std::string trimmed = password;
    trimmed.erase(0, trimmed.find_first_not_of(' '));
    trimmed.erase(trimmed.find_last_not_of(' ') + 1);

    std::string start = trimmed.substr(0, 3);
    std::string end = trimmed.substr(trimmed.length() - 3);

    if (start == "123" || start == "321" || start == "000" || start == "abc" ||
        end == "123" || end == "321" || end == "000" || end == "abc") {
        return false;
    }

    return true;
}

int main() {
    std::string password;
    std::getline(std::cin, password);
    
    if (isValidPassword(password)) std::cout << "sucesso" << std::endl;
    else std::cout << "fracasso" << std::endl;

    return 0;
}
