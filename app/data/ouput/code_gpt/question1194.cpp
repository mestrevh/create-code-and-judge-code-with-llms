/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

char encryptChar(char c) {
    if (std::isalpha(c)) {
        char base = std::isupper(c) ? 'A' : 'a';
        return (c - base + 6) % 26 + base;
    }
    return c;
}

std::string encryptMessage(const std::string& message) {
    std::string encrypted;
    for (char c : message) {
        encrypted += encryptChar(c);
    }
    return encrypted;
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::cout << encryptMessage(line) << std::endl;
    }
    return 0;
}
