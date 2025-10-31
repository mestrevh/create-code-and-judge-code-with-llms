/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool containsDigits(const std::string& s) {
    for (char c : s) {
        if (isdigit(c)) {
            return true;
        }
    }
    return false;
}

int convertToLeet(std::string& s) {
    int count = 0;
    for (char& c : s) {
        switch (c) {
            case 'a':
            case 'A':
                c = '@';
                count++;
                break;
            case 'e':
            case 'E':
                c = '3';
                count++;
                break;
            case 'i':
            case 'I':
                c = '1';
                count++;
                break;
            case 'o':
            case 'O':
                c = '0';
                count++;
                break;
            case 's':
            case 'S':
                c = '5';
                count++;
                break;
            case 't':
            case 'T':
                c = '7';
                count++;
                break;
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string input;
    std::getline(std::cin, input);

    if (input.empty()) {
        std::cout << "vazio" << std::endl;
        std::cout << 0 << std::endl;
        return 0;
    }

    if (containsDigits(input)) {
        std::cout << "numeros" << std::endl;
        std::cout << 0 << std::endl;
        return 0;
    }

    int substitutions = convertToLeet(input);
    std::reverse(input.begin(), input.end());

    std::cout << input << std::endl;
    std::cout << substitutions << std::endl;

    return 0;
}
