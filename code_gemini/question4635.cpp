/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int c;
    std::cin >> c;

    std::cin.ignore();

    std::string s;
    std::getline(std::cin, s);

    for (char &ch : s) {
        if (std::isalpha(ch)) {
            char base = 'A';
            int pos = std::toupper(ch) - base;
            int shift = c % 26;
            int new_pos = (pos + shift + 26) % 26;
            ch = base + new_pos;
        }
    }

    std::cout << s << std::endl;

    return 0;
}
