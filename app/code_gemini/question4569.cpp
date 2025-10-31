/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

bool isValid(const std::string& name) {
    if (name.length() < 3 || name.length() > 30) {
        return false;
    }

    if (!isalpha(name.front()) || !isalpha(name.back())) {
        return false;
    }

    if (!isupper(name[0])) {
        return false;
    }

    for (size_t i = 1; i < name.length(); ++i) {
        char current = name[i];
        char previous = name[i - 1];

        if (!isalpha(current) && current != ' ' && current != '-') {
            return false;
        }

        bool is_current_separator = (current == ' ' || current == '-');
        bool is_previous_separator = (previous == ' ' || previous == '-');

        if (is_current_separator && is_previous_separator) {
            return false;
        }

        if (is_previous_separator && isalpha(current) && !isupper(current)) {
            return false;
        }
    }

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string name;
    std::getline(std::cin, name);

    std::cout << name << ": " << isValid(name) << std::endl;

    return 0;
}
