/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

std::string encrypt(const std::string &text) {
    std::string encrypted = text;
    std::reverse(encrypted.begin(), encrypted.end());

    for (size_t i = 0; i < encrypted.length() - 1; i += 2) {
        std::swap(encrypted[i], encrypted[i + 1]);
    }

    if (text.length() % 2 != 0) {
        char lastChar = encrypted.back();
        encrypted.pop_back();
        encrypted.insert(encrypted.begin(), lastChar);
    }

    return encrypted;
}

std::string decrypt(const std::string &text) {
    std::string decrypted = text;

    if (text.front() == text.back() && text.length() % 2 == 0) {
        char firstChar = decrypted.front();
        decrypted.erase(decrypted.begin());
        decrypted.push_back(firstChar);
    }

    for (size_t i = 0; i < decrypted.length() - 1; i += 2) {
        std::swap(decrypted[i], decrypted[i + 1]);
    }
    
    std::reverse(decrypted.begin(), decrypted.end());
    return decrypted;
}

int main() {
    std::string normalText, encryptedText;
    std::getline(std::cin, normalText);
    std::getline(std::cin, encryptedText);

    std::cout << encrypt(normalText) << std::endl;
    std::cout << decrypt(encryptedText) << std::endl;

    return 0;
}
