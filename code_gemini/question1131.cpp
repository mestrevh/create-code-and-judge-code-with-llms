/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string encrypt(std::string s) {
    int n = s.length();
    if (n == 0) {
        return "";
    }

    std::reverse(s.begin(), s.end());

    for (int i = 0; i + 1 < n; i += 2) {
        std::swap(s[i], s[i + 1]);
    }

    if (n % 2 != 0) {
        char last = s.back();
        s.pop_back();
        s.insert(0, 1, last);
    }

    return s;
}

std::string decrypt(std::string s) {
    int n = s.length();
    if (n == 0) {
        return "";
    }

    if (n % 2 != 0) {
        char first = s.front();
        s.erase(0, 1);
        s.push_back(first);
    }

    for (int i = 0; i + 1 < n; i += 2) {
        std::swap(s[i], s[i + 1]);
    }

    std::reverse(s.begin(), s.end());

    return s;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string to_encrypt;
    std::string to_decrypt;

    std::getline(std::cin, to_encrypt);
    std::getline(std::cin, to_decrypt);

    std::cout << encrypt(to_encrypt) << std::endl;
    std::cout << decrypt(to_decrypt) << std::endl;

    return 0;
}
