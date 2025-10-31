/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>

int main() {
    try {
        std::locale::global(std::locale(""));
    } catch (const std::runtime_error& e) {
        std::locale::global(std::locale("C"));
    }

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);

    std::string n1, n2;
    std::locale loc;

    for (char c : s1) {
        if (std::isalpha(c, loc)) {
            n1 += std::tolower(c, loc);
        }
    }

    for (char c : s2) {
        if (std::isalpha(c, loc)) {
            n2 += std::tolower(c, loc);
        }
    }

    std::sort(n1.begin(), n1.end());
    std::sort(n2.begin(), n2.end());

    if (n1 == n2) {
        std::cout << "True\n";
    } else {
        std::cout << "False\n";
    }

    return 0;
}
