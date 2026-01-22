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

    std::string s;
    std::cin >> s;

    int k;
    std::cin >> k;

    for (char &c : s) {
        c = tolower(c);
        c = 'a' + (c - 'a' + k) % 26;
    }

    std::cout << s << std::endl;

    return 0;
}
